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
