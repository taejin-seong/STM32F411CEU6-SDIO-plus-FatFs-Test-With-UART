## 1. Dev environment<br>
### 1.1.  IDE
* STM32CubeIDE 1.6.0 <br>
* STM32CubeMX <br>

### 1.2.  Terminal Program
* Tera Term <br>

### 1.3.  Development Board
* **STM32F411CEU6 (Black Pill Board)** <br>
  + :pushpin: [Image Link](https://www.google.com/search?q=STM32F411CEU6+Black+Pill&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjZgOijwuj2AhWEe94KHVSECOsQ_AUoAXoECAIQAw&biw=1366&bih=695&dpr=1)<br>
  
### 1.4.  MicroSD & SD Card module 
* Using 8GB MicroSD   (MicroSD capacity is not important)
* Using **NS-SD01** SD Card module 
  + :pushpin: [Image Link](https://nulsom.com/portfolio/ns-sd01_kr/)<br>
  + If the SD card module supports the SDIO interface, it can be tested.
  + In addition, in this project, SD cards are detected using CD pins.
  
<br><br>


## 2. System Configuration Diagram<br>
### 2.1.  Diagram
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160398187-fc8c693d-bd9a-480a-bfae-05104bdede01.png" width="1000" height="400"/> 
<br><br>
</div>		
</details>

### 2.2. Pic
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
  <p align="center">
<img src="https://user-images.githubusercontent.com/70312248/160399052-0920d21e-822b-4273-8fd8-c85caca2ac08.png" width="400" height="300"/> 
</p>
<br><br>
</div>		
</details>



<br><br>


## 3. Where's the file?<br>
### 3.1.  Test file path
<details>
  <summary>:open_file_folder:</summary><br>
  apSDCardTest 함수에서 제공하는 테스트 외에 다양한 테스트를 원할 경우 <strong> 2.2. NOTE </strong>를 참고하세요. <br><br>
  <b> stm32f411ceu6_fw_module → src → ap → ap.c →void apSDCardTest(void){...} </b> <br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160386463-f11051c5-ace4-4a29-b451-8554b4d86eb2.png" width="350" height="350"/> 
<br><br>
</div>		
</details>

### 3.2. NOTE  
<details>
<summary>:open_file_folder:</summary><br>
   STM32에서 제공하는 FAT32 라이브러리를 이용하여 쉽게 SD Card 내의 FAT32 파일 구조 기반의 File 제어가 가능합니다.
   이를 참조하여 추가적인 테스트를 하시는 것을 추천합니다. <br><br>
  <b> stm32f411ceu6_fw_module → src → lib → FatFs → src → ff.h / ff.c </b> <br>
<div markdown="1">
<br>
<img src="https://user-images.githubusercontent.com/70312248/160384410-b2ef6da0-30ea-4cfe-b636-e7e3a2bff3ac.png" width="900" height="850"/> 
 <br><br>
</div>		
</details>


<br><br>

