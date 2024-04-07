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

1. The UE determines the no. of REs Nre' which are available for data transfer within the bandwidth of a single Resource Block using following formula

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/2d36858c-a954-4098-ae97-073e4468c5c7)

- where


![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/c29d4f0c-65a4-446e-95dd-334eeb75dc5e)

2. If the value of Nre' is greater than 156 then Nre' is rounded down to 156, i.e. `the UE never assumes a resource allocation of more than 156 REs  within the bandwidth of a single Resource Block`. The total number of REs within the bandwidth of a single RB is 12 x 14 = 168 using normal cyclic prefix.
3. The final Nre' value is multiplied by the number of allocated Resource Blocks to generate a value for Nre . The number of allocated RBs is extracted from the DCI available through PDCCH, i.e. it is part of the  resource allocation.

![image](https://github.com/KRIISHSHARMA/TBS/assets/86760658/16fe7e4b-6ac1-47bf-bbd7-b03632a82dab)

4. `The value of Nre represents the total no. of REs available for data transfer`
5. The total no. of REs available for data transfer is then converted into a no. of information bits. The no. of information bits depends upon the modulation scheme, the coding rate and the number of layers, i.e. the use of MIMO. The UE uses the following equation standardized by 3GPP .
