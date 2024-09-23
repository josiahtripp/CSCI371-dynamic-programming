#include <iostream>
#include <algorithm>

using namespace std;

int l, t, n; 
int p[100], d[99], tripIntervals[5000][2];
int pr[1000000];

int price(int days);

int best(int start, int a, int b, int end, int &cost);

int main(){

    for(int i = 0; i < 1000000; i++){
        pr[i] = -1;
    }

  /* <----------------------- Load input ---------------------------> */
  cin >> l;//Total number of price levels

  for(int i = 0; i < l; i++){//load price levels
    cin >> p[i];
  }

  for(int i = 0; i < l-1; i++){//Load level intervals
    cin >> d[i];
  }

  cin >> t >> n;//Load total length number of trips

  for(int i = 0; i < n; i++){
    cin >> tripIntervals[i][0] >> tripIntervals[i][1];
  }

    int start = 0;
    int cost = 0;
    for(int i = 0; i < n-1; i++){

        start = best(start, tripIntervals[i][0]-1, tripIntervals[i][1], tripIntervals[i+1][0]-1, cost);
    }
    start = best(start, tripIntervals[n-1][0]-1, tripIntervals[n-1][1], t, cost);

    if(start != t-1){//last call didnt complete

        cost += price(t-start);
    }

    cout << cost;
    return 0;
}

int price(int days){

    if(pr[days] > -1){
        return pr[days];
    }

    int i = 0;
    int price = 0;

    while(days){

        static int m;

        if(i+1 < l){//Is in range of intervals (not last price)
            m = min(days ,d[i]);
        }
        else{//last price
            m = days;
        }

        price += (p[i] * m);
        days -= m;
        i++;
    }
    return price;
}

int best(int start, int a, int b, int end, int &cost){

    if((price(a-start) + price(end-b)) >= price(end-start)){//Extending is cheaper

        return start;
    }
    else{

        cost += price(a-start);
        return b;
    }
}