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
### 0227~0305
**생성파일**
```
company.cpp // 백준 11004(신입사원) 문제
knum.cpp // 백준 1946(k번째 수) 문제
topN.cpp // 백준 11582(치킨 TOP N) 문제
press.cpp // 백준 18870(좌표 압축) 문제
coin.cpp // 백준 2138(동전 0) 문제
switch.cpp // 백준 11047(전구와 스위치) 문제
```
**간단 내용**
- merge sort로 진행하면 시간이 오래 걸린다는 것을 알게됐다.
- stl 없이 구현하는 방법도 좋지만, algorithm의 sort 함수가 가장 적합하다는 것을 알게됐다.
- 벡터 sort만 구현했어서 배열 sort하는 법이 헷갈렸는데, ```sort(arr, arr+size);``` 해주면 된다는 것을 알게됐다. 
- coin 문제의 경우 가장 가치가 높은 동전부터 더해가며 그리디 알고리즘을 쉽게 쓸 수 있었다.
- 하지만 전구와 스위치 문제에 있어서 스위치 on 시작점에 따라 값이 달라졌기 때문에 그리디 알고리즘과 함수 실행을 통한 최솟값 찾기를 합쳐서 실행했다.
- 이번 코드를 통해 그리디 알고리즘이 최적의 알고리즘은 아니란 것을 알았고, 다시 한 번 그리디 알고리즘을 공부할 예정이다.
------
### 0306~0308
**생성파일**
```
lost.cpp // 백준 1541(잃어버린 괄호) 문제
sortinCard.cpp // 백준 1715(카드 정렬하기) 문제 (sorting 오타)
emoticon.cpp // 14226(이모티콘) 문제
algo.cpp // 백준 1261(알고스팟) 문제
```
**간단 내용**
**BFS**
- BFS : 너비 우선 탐색 (최단 경로를 찾을 때 사용)
- c++에서 BFS를 구현하기 위해 queue를 사용
- 방문했는지 여부를 확인할 수 있는 배열이 필요함.
```
int map[10][10] = {0};
int check[10] = {0};
queue<int> q;
int N;

void BFS(int v){
  cout<<v<<" ";
  q.push(v);
  while(!q.empty()){
    int here = q.front();
    q.pop();
    for (int i=0; i<N; i++){
      if (map[here][i]==1 && check[i]==0){
        check[i]=1; // 방문했다
        cout<<i<<" ";
        q.push(i);
      }
    }
  }
}

int main(){
  cin>>N;
  while(1){
    int v1, v2; cin>>v1>>v2;
    if (v1==-1 && v2==-1) break;
    map[v1][v2] = map[v2][v1] = 1; // 쌍방향
  }
  BFS(1);
  return 0;
}
```
------
### 0309~03
코로나 확진으로 인해 몸이 죽을 듯이 아파서 코딩을 하지 못했다... ㅠㅠ       
**생성 파일**
```
treeEsc.cpp // 백준 15900(나무 탈출) 문제
water.cpp // 백준 22511(물통) 문제 - 예제도 다 맞았는데, 반례를 찾아봐야겠다. 틀렸습니다가 뜬다.
DFSBFS.cpp // 백준 1260(DFS와 BFS) 문제
startlink.cpp // 백준 5014(스타트링크) 문제
```
**간단 내용**
**DFS**
- 깊이 우선 탐색
- 스택(Stack)이나 재귀함수를 이용해서 구현할 수 있다.
- 참고 : https://hongku.tistory.com/157
```
int number = 0;
int visit[9];
vector<int> a[10];

void DFS(int start){
    if (visit[start]) return;
    visit[start] = true; // 방문
    cout<<start<<" ";

    for (int i=0; i<a[start].size(); i++){
	int x = a[start][i];
	DFS(x); // 인접한 노드를 방문한 뒤 재귀함수
    }
}

int main(){
    a[1].push_back(2); // 1과 2를 연결
    a[2].push_back(1);
	// ....
    DFS(1); // 1번 노드부터 탐색 실행
    return 0;
}
```
**스패닝 트리**   
- 방향이 없는 그래프에서 모든 노드를 포함하면서 순환되는 경로를 제거한 형태
- 최소 스패닝 트리 : 가중치의 합이 가장 작은 스패닝 트리
- 사용하는 알고리즘 : 크루스칼 알고리즘, 프림 알고리즘
**프림 알고리즘**
참고 : https://yabmoons.tistory.com/363?category=838490
<동작원리>        
- 임의의 시작점 하나 선택하고 이 정점과 연결된 정점들의 거리를 업데이트
- 가장 짧은 길이의 간선을 선택해 연결
- 가장 짧은 간선으로 연결되어 있는 정점을 선택하고, 정점들의 거리 업데이트
- 2~3번 과정을 (전체 노드 갯수 - 1)번 반복
<동작설명>
- 정점과의 거리는 1차원 배열에 저장되어 있다. 이 배열은 정점 갯수대로 있고, 모두 무한대로 저장되어 있는 상태이다.
- 연결된 정점들의 거리를 처음으로 업데이트하는 것은 수동이다.
```
int N, M, Answer;
int Dist[MAX];
bool select[MAX];
vector<pari<int, int>> Cost[MAX];

void Prim_Using_Heap()
{
    priority_queue<pair<int, int>> PQ;
    for (int i = 0; i < Cost[1].size(); i++)
    {
        int Next = Cost[1][i].first;
        int Distance = Cost[1][i].second;
        
        PQ.push(make_pair(-Distance, Next));
    }
    
    Visit[1] = true;
    while (PQ.empty() == 0)
    {
        int Distance = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        if (Visit[Cur] == false)
        {
            Visit[Cur] = true;
            Answer = Answer + Distance;
            for (int i = 0; i < Cost[Cur].size(); i++)
            {
                int nDistance = Cost[Cur][i].second;
                int Next = Cost[Cur][i].first;
                if (Visit[Next] == false) PQ.push(make_pair(-nDistance, Next));
            }
        }
    }
}
```
