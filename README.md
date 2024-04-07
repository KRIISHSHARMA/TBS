# Transport Block
- Transport Block  in 5G NR, is nothing but the payload which is passed between the MAC and Phy Layers, specifically for the shared data channel such as PDSCH and PUSCH
- A Transport Block undergoes Phy layer processing at the transmitter before being mapped onto the PDSCH for transmission over the air interface.
- A Transport block is added with CRC and segmented into code blcoks as shown as below.

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/28b51d15-48c8-4cd3-a04e-fb4d1faba948)

- The transport The transport block consists of up to million bits and the code block consists of up to 8448 bits.

## Factors Affecting TBS
1. No. of Layers (v)
2. Modulation Order (Qm)
3. Coding Rate (R)
4. No. of Physical Resource Block (PRB)
5. No. of Symbols (Nsymb)

## How to Calculated Transport Block Size


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/d9993b0f-ea49-44df-a957-8e0f952a7d91)

1. The UE determines the no. of REs Nre' which are available for data transfer within the bandwidth of a single Resource Block using following formula

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/2d36858c-a954-4098-ae97-073e4468c5c7)

- where


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/c29d4f0c-65a4-446e-95dd-334eeb75dc5e)

2. If the value of Nre' is greater than 156 then Nre' is rounded down to 156, i.e. `the UE never assumes a resource allocation of more than 156 REs  within the bandwidth of a single Resource Block`. The total number of REs within the bandwidth of a single RB is 12 x 14 = 168 using normal cyclic prefix.
3. The final Nre' value is multiplied by the number of allocated Resource Blocks to generate a value for Nre . The number of allocated RBs is extracted from the DCI available through PDCCH, i.e. it is part of the  resource allocation.

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/16fe7e4b-6ac1-47bf-bbd7-b03632a82dab)

4. `The value of Nre represents the total no. of REs available for data transfer`
5. The total no. of REs available for data transfer is then converted into a `no. of information bits`. **The no. of information bits depends upon the modulation scheme, the coding rate and the number of layers, i.e. the use of MIMO. The UE uses the following equation standardized by 3GPP** .


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/8283de42-4523-422b-a140-06002dad0b70)

6. The Modulation Order and Target Code Rate are both extracted from an [MCS table](https://www.techplayon.com/5g-nr-modulation-and-coding-scheme-modulation-and-code-rate/)
7. If Ninfo <= 3824 bits, then TBS is determined based on 3GPP 38.214  - Table 5.1.3.2-1: TBS for N_info <= 3824 and if not then TBS is determined Based on Formula. The detailed step are shown in below flow chart to determine the TBS.


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/c3ca71b4-999c-4aa1-9c7c-16bc20438bbb)

- The threshold of 3824 bit is based upon the maximum code block size of 3840 bits which can be processed by LDPC channel coding .

8. When Ninfo > 3824 then a 24 bit CRC will be added rather than a 16 bit CRC. In addition, segmentation may be required prior to channel coding. When segmentation is applied, an additional 24 bit CRC is added to each segment. The following calculations account for these 24 bit CRC. Ninfo'  is calculated as:

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/2cc9564d-573e-474b-836e-42792896bf7f)

9. The transport block size is then calculated using one of three equations:
   1. If Code Rate <= 0.25 then LDPC ‘Base Graph 2’ will be used (maximum code block size of 3816 + 24 = 3840 bits) and the following equation is applied:

  ![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/44eb7e49-e035-41c9-be12-2fa09df4091c)

  2. Else if N'info > 8424 bits then LDPC ‘Base Graph I’ will be used (maximum code block size of 8424 + 24 = 8448 bits) and the following equation is applied.

  ![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/ebb0474f-e728-451f-a2b3-dd6aec4ebc5e)

  3. Else the following equation is applied:


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/c14b9608-d63c-4b07-8edf-92f39e1ff7bd)
