# Javascript

### 브라우저 동작원리
렌더링 엔진 + 자바스크립트 엔진 → 브라우저가 보여짐
* **렌더링 엔진**  
  - HTML과 CSS 파일을 HTML 파서와 CSS 파서가 가져와서 DOM 트리와 CSSOM 트리를 만든다.  
    → 렌더트리로 결합하여 렌더 트리 기반으로 웹 표시
* **자바스크립트 엔진**  
  - JS로 작성한 코드를 해석/실행하는 인터프리터.  
  - 렌더링 엔진에서 html을 읽다가 script 태그를 만나면, dom 트리 형성을 마치지 않고, script 엔진으로 넘어온다.  
    → script 태그를 html body 맨 아래 둬야 dom 형성 후에 js 호출이 된다. (js에서 생성되지 않은 dom을 호출 할 수도 있음)  

### 자바스크립트 엔진
자바스크립트는 싱글 스레드 언어로 한번에 하나의 태스크만 처리할 수 있다.  
* 구성요소
  - Memory Heap: 메모리 할당이 일어나는 곳 (동적 메모리 할당)
  - Call Stack: 호출 스택이 쌓이는 곳

### V8
- 구글이 주도하여 만든 오픈 소스 자바스크립트 엔진.
- ECMAScript와 웹 셈블리어를 실행함.
- 자바스크립트를 바이트코드로 JIT(Just In Time)컴파일하고 실행.
  1. Parser가 JS code를 AST로 변환
     (Abstract Syntax Tree: 자바 스크립트 코드의 구조를 트리 형식으로 나타냄)
  2. Interpreter가 Syntax Tree로부터 **바이트코드를 생성** → 기계어의 추상화 버전
  3. 터보 팬(optimizing compiler)가 바이트 코드를 최적화된 기계어로 변환
  ![V8 컴파일 파이프라인](https://miro.medium.com/max/700/1*ZIH_wjqDfZn6NRKsDi9mvA.png)
  
