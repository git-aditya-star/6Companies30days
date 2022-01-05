#include<bits/stdc++.h>
using namespace std;

vector<int> GreatestTen(vector<int> &arr){

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<arr.size();i++){ 
        if(pq.size() == 10){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else{
            pq.push(arr[i]);
        }
    }

    vector<int> res;
    for(int i=0;i<10;i++){
       
        int temp = pq.top();
        res.push_back(temp);
        pq.pop();
    }

    return res;

}


int main(){

    long long int n;
    cin>>n;
    vector<int> arr;
    for(int i =0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<int> result;
    result = GreatestTen(arr);
    cout<<endl<<"Top 10"<<endl;
    for(int i =9;i>=0;i--){
        cout<<result[i]<<endl;
    }

}