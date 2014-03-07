#include "smoothing.h"
#include <math.h>

int* init()
{
  ;
}

int deinit()
{
  ;
}

extern int history_SMA[SMA_LENGTH] = {0,};

int simple_mov_avg(int current_value)
{  
  int average=0,sum=0;
  for(int i=1;i<SMA_LENGTH;i++)
  { 
    history_SMA[i-1]=history_SMA[i];
  }
  
  history_SMA[SMA_LENGTH-1]=current_value;
  for(int j=0;j<SMA_LENGTH;j++)
  {
    sum+=history_SMA[j];
  }
  
  average=sum/SMA_LENGTH;
  
  return average;
}

int cumulative_mov_avg(int current_value)  //Seems useless
{ 
  static unsigned long cumulative_average=0;
  static unsigned long k=0;
  k++;
  
  cumulative_average=(current_value+k*cumulative_average)/(k+1);
  return cumulative_average;
}

int exponential_mov_avg(int current_value)
{ 
  static int exponential_average=current_value;
  
  exponential_average=EMA_ALPHA*current_value + (1-EMA_ALPHA)*exponential_average;
  return exponential_average; 
  
}

int history_SG[SG_LENGTH] = {0,};
const long long coefficients[]={1512,-3780,-840,5040,10080,12012,10080,5040,-840,-3780,1512};
const long long normalization_value=36036;


int savitzky_golay(int current_value)
{ 
  long long sum=0;
  int SG_MID = SG_LENGTH/2;
  for(int i=1;i<SG_LENGTH;i++)
  {
         history_SG[i-1]=history_SG[i];
  }
  history_SG[SG_LENGTH-1]=current_value;
    
  for(int i=-SG_MID;i<=(SG_MID);i++)
  {  
    sum+=history_SG[i+SG_MID]*coefficients[i+SG_MID];
  }
  
  history_SG[SG_MID]=sum/normalization_value;
  
  return history_SG[SG_MID];
  
}
    
int history_RDP[RDP_LENGTH] = {0,}; 
//int index_RDP[]={0,};

  
void rdp(int start_index, int end_index)
{
  int a = history_RDP[end_index]-history_RDP[start_index];
  int b = -(end_index-start_index);
  int c = -start_index*a - history_RDP[start_index]*b;
  
  float max_distance = 0;
  int max_index=0;
  float distance = 0;
  
  for( int i=start_index+1;i<end_index;i++)
  {
    distance=(i*a-history_RDP[i]*b+c)/sqrt(a^2+b^2);
    if (distance>max_distance)
    { 
      max_distance=distance;
      max_index=i;
    }
  }
  
  if(max_distance>epsilon)
  { 
        rdp(start_index,max_index);
        rdp(max_index,end_index);
   } 
   else 
    
   {
    for( int i=start_index+1;i<end_index;i++) 
    {
      history_RDP[i]=(-c-a*i)/b;
    }
   }
}
   
int rdp_caller(int current_value)
{ 
  int update_value=history_RDP[0];
  for(int i=1;i<RDP_LENGTH;i++)
  { 
    history_RDP[i-1]=history_RDP[i];  
  }
  
  history_RDP[RDP_LENGTH-1]=current_value;
  
  rdp(0,RDP_LENGTH-1);
  return update_value;
}

int history_KZ[KZ_history_LENGTH] = {0,};
int KZ_MID=(KZ_history_LENGTH)/2;
const long coefficients_k[][17]={{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
                                 {0,0,0,0,1,2,3,4,5,4,3,2,1,0,0,0,0},
                                 {0,0,1,3,6,10,15,18,19,18,15,10,6,3,1,0,0},
                                 {1,4,10,20,35,52,68,80,85,80,68,52,35,20,10,4,1}};
//const long coefficients_k3[]={1,3,6,10,15,18,19,18,15,10,6,3,1};
//const long coefficients_k4[]={1,4,10,20,35,52,68,80,85,80,68,52,35,20,10,4,1};

int kz_filter(int current_value)
{ 
  long divisor=1;
  long updated_value=0; 
  for(int i=1;i<KZ_history_LENGTH;i++)
  {
         history_KZ[i-1]=history_KZ[i];
  }
  
  history_KZ[KZ_history_LENGTH-1]=current_value;
    
  for(int k=1;k<=3;k++)
  {  
    
    for(int i=-k*(KZ_LENGTH-1)/2;i<=k*(KZ_LENGTH-1)/2;i++)
    {
      updated_value+=history_KZ[i+KZ_MID]*coefficients_k[k-1][i+KZ_MID];
    } 
    divisor*=KZ_LENGTH;
    updated_value/=divisor;
    history_KZ[KZ_MID]=updated_value;
   
    updated_value=0;

  } 
   
  return history_KZ[KZ_MID];
   
    
}
