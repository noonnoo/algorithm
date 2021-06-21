# 네트워크 기초
* [프로토콜](#프로토콜)
* [OSI 7계층](#osi-7계층)
* [TCP/IP 프로토콜 스택](#tcpip-프로토콜-스택)
  * [TCP/IP 계층](#tcpip-계층)
* [OSI 계층별 이해](#osi-계층별-이해)
  * [1계층-피지컬 계층](#1계층-피지컬-계층)
  * [2계층-데이터 링크 계층](#2계층-데이터-링크-계층)
  * [3계층-네트워크 계층](#3계층-네트워크-계층)
  * [4계층-트랜스포트 계층](#4계층-트랜스포트-계층)
  * [5계층-세션 계층](#5계층-세션-계층)
  * [6계층-프레젠테이션 계층](#6계층-프레젠테이션-계층)
  * [7계층-애플리케이션 계층](#7계층-애플리케이션-계층)
* [인캡슐레이션과 디캡슐레이션](#인캡슐레이션과-디캡슐레이션)
* [네트워크 토폴로지](#네트워크-토폴로지)
---

### 프로토콜
: 통신규약  
* 물리적 측면: 데이터 전송매체, 신호규약, 회선 규격 등 (이더넷이 널리 쓰임)
* 논리적 측면: 장치들끼리 통신하기 위한 프로토콜 규격. (TCP/IP가 널리 쓰임)  
![image](https://user-images.githubusercontent.com/33820372/115993820-7ace6900-a60f-11eb-814a-494ca774ee46.png)

### OSI 7계층
과거 복잡하고 표준화 되어 있지 않았던 통신용 규약을 통합하려는 노력으로 남게된 산물  
네트워크 동작을 나누어 이해하고 개발하는데 도움이 된다.  
![image](https://user-images.githubusercontent.com/33820372/115993961-08aa5400-a610-11eb-8a85-c116f97e4aec.png)

### TCP/IP 프로토콜 스택
OSI모델보다 실용성을 더 생각한 모델 구조이다.  
애플리케이션 개발자와 서버/네트워크 개발자의 역할 구분이 확연히 드러나는 것이 특징점.  
![image](https://user-images.githubusercontent.com/33820372/115994267-3cd24480-a611-11eb-824e-caf001d59050.png)

#### TCP/IP 계층
##### 응용계층
* 사용자에게 가까운 계층 
* HTTP, SSH, FTP, DNS, SMTP, SNTP등의 프로토콜 사용
* 클라이언트 사이드의 브라우저, 서버가 이 계층에 속함

##### 전송계층
* 전송이 잘 되는지 확인하는 계층
* 패킷의 유실이 없는지, 순서가 제대로 갔는지 등을 확인
* TCP, UDP 프로토콜이 사용됨

##### 인터넷 계층
* 네트워크 목적지를 정하는 계층
* 현재에서 다른 네트워크로 데이터 전송 시 목적지 주소, 단말 주소를 IP 프로토콜을 통해 만듦

##### 링크 계층
* 패킷을 전기신호로 만들어 주고 전기신호를 패킷으로 만들어 받는 계층

---

## OSI 계층별 이해  
![image](https://user-images.githubusercontent.com/33820372/115994365-a2263580-a611-11eb-998e-f33089d85219.png)  
### 1계층: 피지컬 계층
* 물리적 연결과 관련된 정보 정의. (주로 전기신호)
#### 1계층에서 동작하는 네트워크 구성요소
* 네트워크 통신 중재 장비: 허브, 리피터)
* 케이블: 케이블, 커넥터
* 랜 카드와 케이블 연결: 트랜시버 
* 네트워크 모니터링과 패킷 분석을 위해 전기신호 복제: 탭  

### 2계층: 데이터 링크 계층
* 전기 신호를 모아 우리가 알아볼 수 있는 데이터 형태로 처리  
* 주소정보를 정의, 정확한 주소로 통신하는데 초점이 맞춰져 있음.  
* 1계층은 전기신호 보내는게 목적이어서 출발지/목적지 구분이 안되지만, 2계층은 정확히 보내는 것 확인을 위해 주소 확인 후 내게 보낸 것이 맞는지 내가 처리할 게 맞는지 검사 후 데이터 처리.
* 플로 컨트롤: 데이터 받는 사람이 받을 수 있는지 확인.  
#### 2계층에서 동작하는 네트워크 구성요소
- 네트워크 인터페이스 카드: 전기신호 --> 데이터, 목적지 MAC 확인 후 데이터 받거나 폐기 (랜카드, 이더넷 카드, NIC 등으로도 불림)
- 스위치: 포트 필터링, 정확한 포트로 데이터 포워딩  

### 3계층: 네트워크 계층
* IP 주소 같은 논리적 주소가 정의됨.
* IP 주소: MAC주소와 달리 사용자가 환경에 맞게 변경해 사용할 수 있고, 네트워크 주소 부분과 호스트 주소 부분으로 나뉨.
* 네트워크 주소 정보를 이용해 자신이 속한 네트워크와 원격지 네트워크를 구분할 수 있고, 원격지 네트워크까지의 경로 지정할 수 있음.
#### 3계층에서 동작하는 네트워크 구성요소
* 라우터: IP주소 체계를 이해하고 최적의 경로를 찾아 패킷 포워딩  

### 4계층: 트랜스포트 계층
* 데이터들이 잘 보내지는지 확인.
* 패킷 순서를 바로잡아 주는 역할 (패킷 헤더에 보내는 순서/받는 순서를 적어 통신하므로 패킷 유실되면 재전송 요청, 순서가 바뀌면 바로 잡을 수 있음)  

+ 시퀀스 번호: 패킷에 보내는 순서 명시 
+ ACK 번호: 받는 순서 명시

#### 3계층에서 동작하는 네트워크 구성요소
* 로드 밸런서: 포트번호와 시퀀스 번호, SCK 번호 정보를 이용해 부하 분산 처리
* 방화벽: 보안 정책으로 패킷 통과/차단하는 기능 수행

![image](https://user-images.githubusercontent.com/33820372/115995076-bfa8ce80-a614-11eb-8567-2b0687ecf19a.png)
### 5계층: 세션 계층
* 응용 프로세스가 연결을 성립하도록 돕고, 연결이 안정적으로 유지되도록 관리하고 작업 후에는 연결을 끊는 작업을 한다.
* 에러로 중단된 통신에 대해 에러 복구/재전송 수행

### 6계층: 프레젠테이션 계층
* 표현 방식이 다른 애플리케이션/시스템 간의 통신을 돕기 위해 통일된 구문형식으로 변환하는 기능 수행
* MIME 인코딩, 암호화, 압축, 코드 변환 같은 동작 수행

### 7계층: 애플리케이션 계층
* 애플리케이션 프로세스 정의, 애플리케이션 서비스 수행
* 네트워크 소프트웨어의 UI부분이나 사용자 입출력 정의
* 대표적 프로토콜: HTTP, SMTP, FTP, TELNET

---

## 인캡슐레이션과 디캡슐레이션
![image](https://user-images.githubusercontent.com/33820372/116176907-df8fdd80-a74d-11eb-9957-60d51853ec9b.png)
#### 인캡슐레이션
(보내는쪽)애플리케이션에서 데이터를 데이터 플로계층(1~4계층)으로 보내면서 패킷에 데이터를 넣을 수 있게 분할하는 과정
#### 디캡슐레이션
(받는 쪽)받은 데이터가 자신에게 온 것인지 확인(2계층 랜카드가)하고 계층별 헤더를 벗기면서 위의 계층으로 데이터를 올려주는 과정.

##### 헤더에 들어가는 정보
* 현재 계층에서 정의하는 정보  
    ex) 4계층 헤더: 시퀀스, 애크 넘버  
        3계층 헤더: 출발지,도착지의 IP주소  
        2계층 헤더: 출발지 도착지의 MAC 주소 
* 상위 프로토콜 지시자
    * 상위로 갈수록 프로토콜의 종류가 많기 때문에 디캡슐레이션할 때 어떤 상위 프로토콜로 올려야할지 정보가 필요함

---

## 네트워크 토폴로지
* 컴퓨터 네트워크 요소(링크, 노드)를 물리적으로 연결해 놓은 것 혹은 그 연결 방식  
* 물리적 토폴로지(노드,링크의 배치에 따라)와 논리적 토폴로지(노드 사이의 데이터 흐름에 따라)가 있다.
* 토폴로지는 그래프 이론을 사용하여 구성한다.
* 네트워크마다 노드사이의 거리, 물리적 상호연결, 전송 속도, 신호 종류는 다를 수 있지만 토폴로지는 비슷한 양식을 보인다.

* **종류**
  * 버스 토폴로지
    * 버스라는 공통 배선에 각 노드가 연결된 형태, 노드의 신호가 테이블 전체에 전달된다.
    * 장점: 노드의 추가/삭제가 용이하고, 특정 노드이 장애로 다른 노드가 영향 받지 않는다.
    * 단점: 공통 배선의 대역폭을 공유하기 때문에 노드 수가 증가하면 배선의 트래픽이 증가하여 네트워크 선능이 저하된다.  
      <img src="https://user-images.githubusercontent.com/33820372/116804503-3df7fa00-ab5a-11eb-803d-c9587705d615.png" alt="" width="300"/>  
  * 링 토폴로지
    * 각 노드 좌우의 인접한 노드와 연결되어 원형을 이루는 형태
    * 장점: 단방햔 통신으로 신호 증폭이 가능하여 거리 제약이 적다.
    * 단점: 노드의 추가/삭제가 용이하지 않다.  
      <img src="https://user-images.githubusercontent.com/33820372/116804623-1fdec980-ab5b-11eb-9516-544ad794add6.png" alt="" width="300"/>  
  * 스타 토폴로지
    * 각 노드는 중앙에 위치한 주 노드를 통하여 다른 노드와 통신한다.
    * 장점: 장애발견이 쉬복, 관리가 용이하다.
    * 단점: 주노드에 장애가 발생하면 전체 네트워크 사용이 불가하다.   
      <img src="https://user-images.githubusercontent.com/33820372/116804591-e7d78680-ab5a-11eb-9b5b-a72ff2035099.png" alt="" width="300"/>  
  * 트리 토폴로지
    * 버스형 토폴로지를 변형한 형태로, 하나의 노드에 여러 노드가 연결되있다. 양방향으로 모든 노드에 데이터 전송  
    * 장점: 네트워크 확장이 쉽고, 관리가 편하다. 통신 선로가 짧고 통신회선수 절약이 가능하다.
    * 단점: 상위 회선에 문제가 생기면 하위 회선 모두 문제가 생기낟.네트워크 확장이 많아지면 트래픽 집중이 생기기도 한다.  
      <img src="https://user-images.githubusercontent.com/33820372/116804667-8663e780-ab5b-11eb-933b-d43c357c261c.png" alt="" width="300"/>  
  * 메쉬 토폴로지
    * 단말기들이 직접 상호 연결되어 그물처럼 연결된 형태로, 모든 네트워크와 컴퓨터가 개별적으로 연결되어 있다.
    * 장점: 특정 통신 회선 문제가 생겨도 다른 경로로 데이터 전송이 가능하다. 가용성이 높고, 효율성이 좋다.
    * 단점: 네트워크 관리, 설치 ,재구성이 어렵다. 많은 링크를 사용하기 때문에 설치 비용이 많이 든다.  
      <img src="https://user-images.githubusercontent.com/33820372/116804704-e35f9d80-ab5b-11eb-9157-cd9dc7d81758.png" alt="" width="300"/>  
      
***참고***  
[위키백과](https://ko.wikipedia.org/wiki/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC_%ED%86%A0%ED%8F%B4%EB%A1%9C%EC%A7%80)  
[브릭봇님 블로그](https://m.blog.naver.com/PostView.nhn?blogId=brickbot&logNo=220418950837&proxyReferer=https:%2F%2Fwww.google.com%2F)  
[하이라인닷넷님 블로그](https://m.blog.naver.com/hilineisp/10169694570)  
  