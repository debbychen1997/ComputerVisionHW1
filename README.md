# ComputerVisionHW1
## 對image做convolution
**1. Image blur <br/>**
blur kernel: <br/>
0.0625 0.125 0.0625 <br/>
0.125 0.25 0.125 <br/>
0.0625 0.125 0.0625 <br/><br/>
<img src="https://github.com/debbychen1997/ComputerVisionHW1/blob/main/image/blur.png" width="500px" > <br/>

**2. Image Outline <br/>**
Outline kernel: <br/>
-1 -1 -1 <br/>
-1 8 -1 <br/>
-1 -1 -1 <br/><br/>
<img src="https://github.com/debbychen1997/ComputerVisionHW1/blob/main/image/outline.png" width="500px" > <br/>

**3. Image Sharpen <br/>**
Sharpen kernel: <br/>
0 -1 0 <br/>
-1 5 -1 <br/>
0 -1 0 <br/><br/>
<img src="https://github.com/debbychen1997/ComputerVisionHW1/blob/main/image/Sharpen.png" width="500px" > <br/>

## Instruction:
1.	在程式碼中輸入圖檔所在位置
2.	在程式碼中輸入input text檔案所在位置
3.	在text檔輸入奇數大小的矩陣，小數或是整數
