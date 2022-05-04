## Dev environment<br>
### IDE
* STM32CubeIDE 1.6.0 <br>
* STM32CubeMX <br>

### Terminal Program
* Tera Term <br>

### Development Board
* **STM32F411CEU6 (Black Pill Board)** <br>
  + :pushpin: [Image Link](https://www.google.com/search?q=STM32F411CEU6+Black+Pill&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjZgOijwuj2AhWEe94KHVSECOsQ_AUoAXoECAIQAw&biw=1366&bih=695&dpr=1)<br>
  
### MicroSD & SD Card module 
* Using 8GB MicroSD   (MicroSD capacity is not important)
* Using **NS-SD01** SD Card module 
  + :pushpin: [Image Link](https://nulsom.com/portfolio/ns-sd01_kr/)<br>
  + If the SD card module supports the SDIO interface, it can be tested.
  + In addition, in this project, SD cards are detected using CD pins.
  
<br>


## System Configuration<br>
### Diagram
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160398187-fc8c693d-bd9a-480a-bfae-05104bdede01.png" width="1000" height="400"/> 
<br><br>
</div>		
</details>

### Pic
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



<br>


## Where's the file?<br>
### Test file path
<details>
  <summary>:open_file_folder:</summary><br>
  apSDCardTest 함수에서 제공하는 테스트 외에 다양한 테스트를 원할 경우 <strong> NOTE </strong>를 참고하세요. <br><br>
  <b> stm32f411ceu6_fw_module → src → ap → ap.c →void apSDCardTest(void){...} </b> <br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160386463-f11051c5-ace4-4a29-b451-8554b4d86eb2.png" width="350" height="350"/> 
<br><br>
</div>		
</details>

### NOTE  
<details>
<summary>:open_file_folder:</summary><br>
   STM32에서 제공하는 FatFS 라이브러리의 API를 이용하면 SD Card 내에 FAT32 파일 시스템 구조 기반의 File 제어 (생성/W/R/삭제/이동/변경 등..)가 아주 쉽게 가능해집니다.
   이를 참조하여 추가적인 테스트를 하시는 것을 추천합니다. <br><br>
  <b> stm32f411ceu6_fw_module → src → lib → FatFs → src → ff.h / ff.c </b> <br>
<div markdown="1">
<br>
<img src="https://user-images.githubusercontent.com/70312248/160384410-b2ef6da0-30ea-4cfe-b636-e7e3a2bff3ac.png" width="900" height="850"/> 
</div>		
</details>


<br>


## STM32Cube MX Setting<br>
### Clock Configuration
<details>
<summary>📌</summary><br> 
<div markdown="1">
<img src="https://user-images.githubusercontent.com/70312248/160401801-273d9fa9-4093-44ee-af39-6bb46ed37f52.png" width="1180" height="900"/> <br>
<br><br>
</div>
</details>


<hr/>

### Pinout<br>
<details>
<summary>📌</summary><br>  
<div markdown="1">
  <p align="center">
<img src="https://user-images.githubusercontent.com/70312248/160402063-85014d81-f34e-427f-bc57-0566f15d0777.png" width="800" height="700"/> <br>
  </p>
<br><br>
</div>
</details>

<hr/>

### Peripheral & Core Configuration<br>
#### 1. UART1

<details>
<summary>📌</summary><br>
• You can change parameter settings in uart.c <br><br>
<div markdown="1">
<img src="https://user-images.githubusercontent.com/70312248/160402633-56a78521-7b07-4a0c-9a59-8e083e8607a3.png" width="1000" height="800"/>
<br><br>
</div>
</details>


#### 2. SDIO

<details>
<summary>📌</summary><br>
<div markdown="1">
<img src="https://user-images.githubusercontent.com/70312248/160402880-97229693-11d0-4f35-9959-96125fa9746c.png" width="1000" height="800"/>
<br><br>
</div>
</details>


#### 3. GPIO
<details>
<summary>📌</summary><br> 
• SD Card Protocol에서 SDIO로 interface할 때 CD Pin은 필요없습니다. 이는  단지 SD Card 모듈에서 지원해주는 Pin입니다. SD 카드가 꽂히면(Detected), CD Pin은 <b>High → Low</b>로 동작합니다.  <br><br>
<div markdown="1">
<img src="https://user-images.githubusercontent.com/70312248/160403251-0f112dcd-e8fe-4e8b-8304-f30705099461.png" width="1000" height="800"/> 
<br><br>
</div>
</details>



#### 4. DMA
<details>
<summary>📌</summary><br>  
<div markdown="1">
  • <b> USART1 DMA Request Setting </b> <br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;[USART1_RX]&nbsp;:&nbsp;&nbsp;Mode → <b>Circular</b> <br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;[USART1_TX]&nbsp;:&nbsp;&nbsp;Mode → <b>Normal</b> (All Default) <br>
  <br>
  • <b> SDIO DMA Request Setting </b> <br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;[SDIO_RX]&nbsp;:&nbsp;&nbsp;All Default <br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;[SDIO_TX]&nbsp;:&nbsp;&nbsp;All Default <br>
  <br><br>
<img src="https://user-images.githubusercontent.com/70312248/160404638-6a264645-1f7f-4b07-a70e-f29ed1226ae5.png" width="1000" height="800"/> 
<br><br>
</div>
</details>


#### 5. NVIC
<details>
<summary>📌</summary><br>  
<div markdown="1">
<img src="https://user-images.githubusercontent.com/70312248/160405151-1796c670-cc28-450e-8a2d-f00c9401ad32.png" width="1000" height="800"/> 
<br><br>
</div>
</details>


#### 6. Middeware - FATFS
<details>
<summary>📌</summary><br>  
<div markdown="1">
• 직접 FATFS 파일 시스템을 포팅하였습니다. 
</div>
</details>



<br>


##  Testing<br>
### 1.  Sd Card Detection and Information print
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160411780-dad0e296-969f-4faf-9593-89a0cc842baf.png" width="1300" height="750"/> 
<br><br>
</div>		
</details>

### 2.  a
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160412185-48078a05-6e51-40d0-a333-8cb10c92b53b.png" width="1300" height="750"/> 
<br><br>
</div>		
</details>



### 3.  b
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
• SD Card root directory current state <br><br>
<img src="https://user-images.githubusercontent.com/70312248/160413609-552fc1e4-586c-4115-8094-360147da70dd.png" width="700" height="400"/> 
<br>

<p align="center">
<img src="https://user-images.githubusercontent.com/70312248/160412539-3544aea2-b594-4892-a461-e4534497d9ab.png" width="1300" height="750"/> 
</p> <br>

  
  
<br>
</div>		
</details>

### 4.  c
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
  • SD Card root directory current state <br><br>
<img src="https://user-images.githubusercontent.com/70312248/160413609-552fc1e4-586c-4115-8094-360147da70dd.png" width="700" height="400"/> 
<br>
<img src="https://user-images.githubusercontent.com/70312248/160414219-39524921-67cf-4559-aa5b-10948806d4de.png" width="1300" height="750"/> 
<br><br>
</div>		
</details>

### 5.  d
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160414412-e0edba11-a419-4eab-bb59-d74ffe97b947.png" width="1300" height="750"/> 
<br><br>
• SD Card root directory current state <br><br>
<img src="https://user-images.githubusercontent.com/70312248/160414642-9778f312-0019-4ae9-9218-e4f04f17b14b.png" width="700" height="400"/> 
<br><br><br>
• Test C again <br><br> 
<img src="https://user-images.githubusercontent.com/70312248/160415153-dafdf85c-7637-4dae-83f8-6183740c6a74.png" width="1300" height="750"/> 
<br><br><br>
• HelloWorld.csv <br><br> 
<img src="https://user-images.githubusercontent.com/70312248/160416575-ddac45d0-9ae2-4357-acd9-82d23a1bc152.png" width="1000" height="550"/> 
  <br><br> 
</div>		
</details>

### 6.  e
<details>
  <summary>:pushpin:</summary><br>
<div markdown="1">
 <br>
<img src="https://user-images.githubusercontent.com/70312248/160416935-69f1774c-1fb3-42cb-ad90-c6c8f2f2a6fc.png" width="1300" height="750"/> 
<br><br>
• SD Card root directory current state <br><br>
<img src="https://user-images.githubusercontent.com/70312248/160417171-35900daf-f0c3-4ccd-b318-c20585d47bc8.png" width="700" height="400"/> 
<br><br>
</div>		
</details>


<br>

## Note <br>
* When you build a project, you must exclude folders in the following paths from the build and debug entries: <br>

  + **`src → lib → Core`**

## Refer to<br>
https://github.com/chcbaram/stm32f411


