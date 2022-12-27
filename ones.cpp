#include<iostream>

using namespace std;

int calc_multiplier(int n){

  int map[10];
  int k, mul, rem, cnt = 0;
  for(int i=0;i<10;i++) map[i] = -1;
  map[0] = 0;

  //Mapping numbers
  for(int i=1;i<10;i++){
    k = (n*i)%10;
    map[k] = i;
    //cout<<k<<" "<<map[k]<<" ";
  }
  //cout<<"\n";
  int carry = 0;
  int curr_num = n;
  int unit_num = 0;
  int flag = 1;

  while(curr_num>0){
    unit_num = curr_num%10;
    //cout<<curr_num<<" "<<unit_num<<"\n";
    if(unit_num == 0 || flag == 1){
      mul = map[1];
      flag = 0;
    }
    else if(unit_num == 1){
        mul = 0;
    }
    else{
      mul = map[11-unit_num];
    }
    rem = n*mul + carry;
    cnt++;
    carry = rem/10;
    curr_num = carry;
    //cout<<curr_num<<"\n";
  }
  return cnt;
}

int main(){
  int n;
  //cin>>n;
  //cout<<n;
  while(cin>>n){
    //cout<<n<<"\n";
    cout<<calc_multiplier(n)<<"\n";
  }
}