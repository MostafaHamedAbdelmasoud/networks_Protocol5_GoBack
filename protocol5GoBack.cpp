#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n;
vector<int> packets,failedIndicies;
int freq[N];

int main(){
    bool again = 1;
    while(again){
        memset(freq , 0 ,sizeof freq);
        packets.clear(),failedIndicies.clear();
        printf("number of frames : ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            printf("value of frame %d :", i + 1);
            scanf("%d", &x);
            packets.push_back(x);
        }
    int sz = packets.size();
    int m;
    printf("Assume a number of indexes lost in medium ,Zero for no losses : \n");
    printf("enter numbers of failed frames: ");
    scanf("%d", &m);
    printf(" start sending: \n");
    if(!m){
        printf("%s","from network_layer to physical_layer");
        for(int x: packets){
            printf("%d %s\n", x," succfuly sent");
        }
    }
    else{
        for (int i = 0; i < m; i++)
        {
            int d;
            printf(" enter %d failed index number: ",i+1);
            scanf("%d",&d);
            if(d>sz) {
                puts("wrong index\n");
                return 0;
            }
            if(!freq[d])
                failedIndicies.push_back(d);
            freq[d]=1;
        }
            sort(failedIndicies.begin(), failedIndicies.end());
        printf(" start sending: \n");
        for (int i = 0; i < sz; i++)
        {
            if ((i + 1) <= failedIndicies[0])
            {
                printf("%d -> Succefully sent\n", i + 1);
            }
            else
                printf("%d -> Failed \n", i + 1);
        }
        int failedSize = failedIndicies.size();
        int failedCpy = failedSize;
        int indx =0;
        int lst=0;
        while (failedCpy--){
            printf("sending acknowledgement now\n");
            printf(" Sucessfully sent acknowledgement from frame index (%d) now  \n\n", failedIndicies[indx]);
            printf("%s", "from network_layer to physical_layer\n\n");
            // for (int i = failedIndicies[indx]; indx < failedSize, i < failedIndicies[indx + 1]; i++)
            // {
            if (indx >= failedSize){
                for (int i = lst; i < sz; i++)
                {
                    printf("%d -> %s\n", packets[lst], " succfuly sent");
                }
                break;
            }
                for (int j = failedIndicies[indx]; j < sz; j++)
                {
                    if (failedIndicies[indx + 1] == 0){
                        printf("%d -> %s\n", packets[j], " succfuly sent");
                    }
                    else{
                        if (j <= failedIndicies[indx + 1] - 1)
                            printf("%d -> %s\n", packets[j], " succfuly sent");
                        else
                            printf("%d -> %s\n", packets[j], " failed ");
                    }
                     lst =j;
                }
                
                // printf("%d %s\n", packets[i], " succfuly sent");
            // }
            
            indx++;
        }
    }
        printf("press 1 to Try another example , else terminate -> [1/0]? : ");
        int inp ;
        scanf("%d",&inp);
        again = inp;
    }

        return 0;
}










/*
*/