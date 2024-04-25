#include <iostream>
#include <cmath>
#define DMRSREsinaPRB 12
#define DMRSREinaPRBsymbol2  24
#define NRB_SC 12
#define FAILURE 0


class PDSCHCalculator {
private:
    int IMCS[32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    int Qm64[32] = {2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,6,2,4,6};
    int Qm256[32] =  {2,2,2,2,2,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,2,4,6,8};
    float R64QAM[32] = {120,157,193,251,308,379,449,526,602,679,340,378,434,490,553,616,658,438,466,517,567,616,666,719,772,822,873,910,948,0,0,0};
    float R256QAM[32] = {120,193,308,449,602,378,434,490,553,616,658,466,517,567,616,666,719,772,822,873,682.5,711,754,797,841,885,916.5,948,0,0,0,0};


public:
    void calculatePDSCH() {
        int MCS_Table;
        std::cout << "Please state the MCS table to use:\n"
                     "0 - 64QAM\n"
                     "1 - 256QAM\n"
                     "> ";
        std::cin >> MCS_Table;

        int MCS, Modulation_order, numlayers, Nsh_Sym, NRE_DMRS, Overhead, Total_prbs , DMRS_SYM , DMRS_ADDPOS;
        std::cout << "Enter the MCS value: ";
        std::cin >> MCS;

        int MCS_Index = getIndex(MCS);
        
        Modulation_order = getQm(MCS_Table, MCS_Index);

        float Code_Rate = getCodeRate(MCS_Table, MCS_Index);

        std::cout << "The code rate used is " << Code_Rate << " and modulation order is " << Modulation_order << std::endl;

        std::cout << "Enter number of layers: ";
        std::cin >> numlayers;
        
        getports(numlayers);
        
        std::cout << "Number of symbols of the PDSCH allocation within the slot: ";
        std::cin >> Nsh_Sym;
        
        // DMRS CONFIG

        std::cout << "DMRS Single or Double symbol: ";
        std::cin >> DMRS_SYM;
        
        std::cout << "DMRS Additional position: ";
        std::cin >> DMRS_ADDPOS;
        
        NRE_DMRS = getdmrsre(DMRS_SYM , DMRS_ADDPOS);
        
        std::cout << "Overhead configured by higher layer parameter Xoh-PDSCH: ";
        std::cin >> Overhead;
        std::cout << "Total number of allocated PRBs for the UE: ";
        std::cin >> Total_prbs;
        int nre_prb = (NRB_SC * Nsh_Sym) - NRE_DMRS - Overhead;
        int NRE = std::min(156, nre_prb) * Total_prbs;
        float N_info = NRE * Code_Rate * Modulation_order * numlayers;

        std::cout << "Intermediate number of information bits are " << N_info << std::endl;
        float TBS ;
        if (N_info <= 3824) {
            int n = std::max(3, std::log2(N_info) - 6);
            int N_info_quant_1 = std::max(24,  (std::pow(2, n)) * std::floor(N_info / std::pow(2, n)));
            std::cout << "Quantized intermediate number of information bits: " << N_info_quant_1 << std::endl;
        } else {
            int n =  (std::log2(N_info - 24)) - 5;
            int N_info_quant =  (std::pow(2, n)) *  (std::round((N_info - 24) / std::pow(2, n)));
            std::cout << "Quantized intermediate number of information bits: " << N_info_quant << std::endl;

            if (Code_Rate <= 0.25) {
                std::cout << "\ncode rate <= 0.25\n";
                int C = ceil((N_info_quant + 24) / 3816.0);
                TBS = 8 * C * ceil((N_info_quant + 24) / (8 * C)) - 24;
                std::cout << "\nTransport Block Size: " <<TBS<<" bits\n";
            } else {
                std::cout << "\ncode rate > 0.25\n";
                if (N_info_quant >= 8424) {
                    std::cout << "\nQuantized intermediate number of information bits >= 8424\n"; 
                    float C = ceil((N_info_quant + 24) / 8424.0);
                    TBS = 8 * C * ceil((N_info_quant + 24) / (8 * C)) - 24;
                    std::cout << "\nTransport Block Size: " <<TBS<<" bits\n";
                } else {
                    std::cout << "\nQuantized intermediate number of information bits < 8424\n";
                    TBS = 8 * ceil((N_info_quant + 24) / 8) - 24;
                    std::cout << "\nTransport Block Size: " <<TBS<<"bits\n";
                }
            }
        }
    }

private:
    int getIndex(int MCS) {
        for (int i = 0; i < 32; ++i) {
            if (IMCS[i] == MCS) {
                return i;
            }
        }
        return -1; // MCS not found
    }
    int getQm(int table, int index) {
        if (table == 0) {
            return Qm64[index] ;
        } else if (table == 1) {
            return Qm256[index] ;
        } else {
            return 0.0; // Invalid table
        }
    }
    float getCodeRate(int table, int index) {
        if (table == 0) {
            return R64QAM[index] / 1024.0;
        } else if (table == 1) {
            return R256QAM[index] / 1024.0;
        } else {
            return 0.0; // Invalid table
        }
    }
    
    void getports(int numlayers) {
        if (numlayers > 4) {
            std::cout << "WRONG NUMBER OF LAYERS FOR CW0";
            exit(1);
        }
        int port = 1000;
        std::cout << "PORTS : ";
        for (int i = 0 ; i < numlayers ; i++){
            std::cout << port << " ";
            port++;
        }
        std::cout << std::endl;
    }
    
    int getdmrsre(int symbols , int addpos){
        if (symbols == 1) {
            return DMRSREsinaPRB ;
        } else if  (symbols == 2) {
            return DMRSREinaPRBsymbol2 ;
        } else {
            return FAILURE ;
        }
    }
};

int main() {
    PDSCHCalculator calculator;
    calculator.calculatePDSCH();
    return 0;
} 


