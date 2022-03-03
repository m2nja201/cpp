## C++ Study 기록장

- 파일 확인을 위해 2월 13일부터 기록 시작    
- 일주일에 한 두 번 기록할 예정    
### 0213
**생성파일**
```
org.cpp // 코딩테스트를 위한 자료구조와 알고리즘 with C++ 연습문제(회사 조직도)
graphEx1.cpp // 코딩테스트를 위한 자료구조와 알고리즘 with C++ 연습문제(인접 행렬을 사용해 그래프 구현)
graphEx2.cpp // 코딩테스트를 위한 자료구조와 알고리즘 with C++ 연습문제(인접 리스트를 사용해 그래프 구현)
```
**간단 내용**
- 이진 트리와 이진트리 traversal 종류에 대해 연습
- 인접행렬을 이용해 그래프를 구성 (+ enum class에 대해 알게됨)
- 인접리스트를 이용해 그래프를 구성      
**enum class**
열거형 클래스로 강한 형식과 범위를 가진다. ```enum class``` 키워드를 사용하면 되고, 범위 한정자(::)를 이용해 열거자에 접근해야 한다.    

------
### 0217
**생성파일**    
```
maxHeap.cpp // 백준 11279 문제(최대 힙) 최종 답안         
maxHeap_update.cpp // 백준 11270 문제(최대 힙) 수정 전 답안
island.cpp // 이름 잘못 표기! maze.cpp로 바꿀 예정 백준 2178 (미로탐색) 답안
```
**간단 내용**     
- 최대 힙 문제는 처음부터 쉽게 풀었지만, 시간 초과가 되는 바람에 계속 업로드를 실패했다.        
- cin.tie(0)도 설정해 줬고, ios_base::sync_with_stdio(false)도 설정해줬는데, 시간은 줄지 않았다.        
- 스터디 친구가 endl을 \n으로 써보라고 했는데 세상에나 됐다. 난 새벽 내내 울먹거렸는데..!        
- 조금이라도 빠른 코드를 작성하기 위해 더 공부해야겠다!       
- commit을 잘못했다. ``` 0216 java study -> 0217 c++ study```      
------
### 0220~0225
**생성파일**
```
10430.cpp // 기본 문제
simpleBackpack.cpp // 기본 문제
11098.cpp // 기본 문제
lonString.cpp // (longString) 백준 3033문제(가장 긴 문자열) 수정 전 답안
findNum.cpp // 백준 1920 문제(수 찾기)
ioioi.cpp // 백준 5525 문제(IOIOI) 수정 전 답안
newIOIOI.cpp // 백준 5525 문제(IOIOI) 최종 답안
longS.cpp // 백준 3033 문제(가장 긴 문자열) 최종 답안
sumArray.cpp // 백준 11728 문제(배열 합치기)
sorting2.cpp // 백준 2751 문제(수 정렬하기2)
point.cpp // 백준 11650 문제 (좌표 정렬하기)
sumofnone.cpp // 프로그래머스 '없는 숫자 더하기' 문제 [출처 링크](https://programmers.co.kr/learn/courses/30/lessons/86051)
englishWord.cpp // 프로그래머스 '숫자 문자열과 영단어' 문제 [출처 링크](https://programmers.co.kr/learn/courses/30/lessons/81301)
```    
**간단 내용**
- c++ 공부한 것도 기록하고 있었음을 까먹었다.. 폭풍 업로드..
- 가장 긴 문자열은 시간 초과가 났었다. while안에 for문을 두 개나 써서 그랬다. 이분 탐색으로 해결할 수 있었다.
- 수 찾기와 IOIOI는 해시테이블을 사용하지 않았다. 훨씬 간결한 코드로 적었다.
- 즉, ioioi.cpp는 해시테이블을 사용해서 푼 답, newIOIOI.cpp는 문자열을 사용해 푼 답이다.
- sumArray.cpp부터 point.cpp는 vector와 algoritm 헤더가 있어 쉽게 풀 수 있었다.
- endl을 "\n"으로 바꿔서 사용하는 꿀팁을 알게된 이후 백준에 재출할 때 잘 쓰고 있다.
------
### 0225~0226
**생성파일**
```
kNum.cpp // 프로그래머스 'k번째 수' 문제 [출처 링크](https://programmers.co.kr/learn/courses/30/lessons/42748)
machineGame.cpp // 프로그래머스 '크레인 인형뽑기 게임' 문제 [출처 ](https://programmers.co.kr/learn/courses/30/lessons/64061)
```
**간단 내용**
- c++ 기본 문제를 풀면서 기본기도 다지고, 성공한 문제를 java로 다시 풀어보는 연습을 하는 중이다.
- c++은 Lv.1문제 두 개만 더 풀고 Lv.2 문제로 넘어가도 될 것 같다.
------
### 0227~0303
**생성파일**
```
company.cpp // 백준 11004(신입사원) 문제
knum.cpp // 백준 1946(k번째 수) 문제
topN.cpp // 백준 11582(치킨 TOP N) 문제
press.cpp // 백준 18870(좌표 압축) 문제
```
**간단 내용**
- merge sort로 진행하면 시간이 오래 걸린다는 것을 알게됐다.
- stl 없이 구현하는 방법도 좋지만, algorithm의 sort 함수가 가장 적합하다는 것을 알게됐다.
- 벡터 sort만 구현했어서 배열 sort하는 법이 헷갈렸는데, ```sort(arr, arr+size);``` 해주면 된다는 것을 알게됐다.
------
