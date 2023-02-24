#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_DEPTH = 18; // 세그먼트 트리의 높이
const int MAX_ST = 1<<MAX_DEPTH; // 초기화에 사용되는 노드 개수
const int MAX = 10001; // 점의 개수
const int MAX_RANGE = 100001; // 좌표값의 범위
const int MAX_NODE = MAX_ST + MAX*MAX_DEPTH; // 문제 전체에서 사용되는 노드 개수의 상한
 
// 세그먼트 트리 노드
struct Node{
    int val; // 값: 이 노드가 포함하는 구간 합
    int ns, ne; // 이 노드는 구간 [ns, ne)를 담고 있다.
    int nNum; // 이 노드의 번호는 nNum이다.
    int lNum, rNum; // 이 노드의 왼쪽 자식, 오른쪽 자식 노드의 번호
    Node(): Node(-1, -1, -1){}
    Node(int ns1, int ne1, int nNum1): val(0), ns(ns1), ne(ne1), nNum(nNum1), lNum(-1), rNum(-1){}
};
 
struct PersistentSegTree{
    int TN; // 현재 트리의 개수
    int ncnt; // 현재 노드의 개수: 새 노드의 번호를 붙일 때 사용
    int root[MAX]; // root[k]: k번째 트리의 루트 노드 번호
    Node node[MAX_NODE];
 
    PersistentSegTree(): TN(0), ncnt(0){
        fill(root, root+MAX, -1);
        // 0번 트리를 비어있는 포화 이진 트리로 구축한다. 따라서 항상 TN = 1로 시작
        root[TN++] = initialize(0, MAX_ST/2);
    }
 
    // 초기화: 비어있는 포화 이진 트리 구축 후 0번 트리로 설정
    int initialize(int s, int e){
        Node &curr = node[ncnt] = Node(s, e, ncnt);
        ncnt++;
        if(s+1 < e){
            int mid = (s+e)/2;
            curr.lNum = initialize(s, mid);
            curr.rNum = initialize(mid, e);
        }
        return curr.nNum;
    }
 
    // 새 트리를 만들면서 인덱스 y인 리프 노드에 val만큼 더함
    void addNode(int y, int val = 1){
        
        // 새 트리를 만들어서 루트 노드 번호를 저장
        root[TN] = addNode(node[root[TN-1]], y, val, 0, MAX_ST/2);
        ++TN;
    }
    int addNode(Node &shadow, int y, int val, int s, int e){
        // 노드의 구간이 y를 포함하지 않으면 이 자리의 이전 트리 노드를 돌려줌(갱신 X)
        if(e <= y || y < s) return shadow.nNum;
 
        // 노드를 하나 새로 만듦(갱신 O)
        Node &curr = node[ncnt] = Node(s, e, ncnt);
        ncnt++;
        // 리프 노드
        if(s+1 == e) curr.val = shadow.val + val;
        // 인터널 노드
        else{
            int mid = (s+e)/2;
            // 왼쪽 자식 연결
            curr.lNum = addNode(node[shadow.lNum], y, val, s, mid);
            // 오른쪽 자식 연결
            curr.rNum = addNode(node[shadow.rNum], y, val, mid, e);
            // 자신의 구간 합을 구함
            curr.val = node[curr.lNum].val + node[curr.rNum].val;
        }
        // 이번에 만든 노드의 번호를 리턴
        return curr.nNum;
    }
 
    // tn번째 트리의 구간 [s, e)의 합을 구함
    int sum(int tn, int s, int e){
        return sum(node[root[tn]], s, e);
    }
    int sum(Node &curr, int s, int e){
        if(e <= curr.ns || curr.ne <= s) return 0;
        if(s <= curr.ns && curr.ne <= e) return curr.val;
        return sum(node[curr.lNum], s, e) + sum(node[curr.rNum], s, e);
    }
};
//[출처] 퍼시스턴트 세그먼트 트리(Persistent Segment Tree) (수정: 2019-11-10)|작성자 라이
