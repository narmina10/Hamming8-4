# Hamming (8,4)

This is a realization of a **Hamming (8,4)** code for error detection and correction.<br>
It defines functions Hamming84_encode to encode a 4-bit data into an 8-bit Hamming code and Hamming84_decode to decode the received code, detect errors, and correct if possible using parity bits.<br> The main function demonstrates encoding and decoding a sample data sequence, showing the error detection and correction capabilities of the Hamming (8,4) code. <br><br>


The code was realizes using the following mathematical formulas: <br><br>

**p1** = 1 $\oplus$ d1 $\oplus$ d3 $\oplus$ d4 <br>
**p2** = 1 $\oplus$ d1 $\oplus$ d2 $\oplus$ d4 <br>
**p3** = 1 $\oplus$ d1 $\oplus$ d2 $\oplus$ d3 <br> 
**p4** = 1 $\oplus$ p1 $\oplus$ d1 $\oplus$ p2 $\oplus$ d2 $\oplus$ p3 $\oplus$ d3 $\oplus$ d4 <br> <br>

**A** = p1 $\oplus$ d1 $\oplus$ d3 $\oplus$ d4 <br>
**B** = p2 $\oplus$ d1 $\oplus$ d2 $\oplus$ d4 <br>
**C** = p3 $\oplus$ d1 $\oplus$ d2 $\oplus$ d3 <br>
**D** = p1 $\oplus$ d1 $\oplus$ p2 $\oplus$ d2 $\oplus$ p3 $\oplus$ d3 $\oplus$ p4 $\oplus$ d4
