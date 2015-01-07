#include <math.h>
#include <stdio.h>
 
/* SUPPORTED CONFIDENCE LEVELS: 50%, 68%, 90%, 95%, and 99% */
float confidence_level_constant[5][2] = {{50, .67},{68, .99},{90, 1.64},
                                         {95, 1.96}, {99, 2.57}};
 
/* CALCUALTE THE SAMPLE SIZE */
int sample_size(long long population_size, 
                float confidence_level, 
                float confidence_interval)
{
  float Z; /* Z SCORE */
  float p; /* VARIANCE */
  float e; /* ERROR */
  long long N; /* POPULATION SIZE */
  float n_0;
  float n;
 
  Z = 0.0;
  p = 0.5; /* MAX VARIANCE */
  e = (confidence_interval/100.0);
  N = population_size;
  n_0 = 0.0;
  n = 0.0;
 
  /* LOOP THROUGH SUPPORTED CONFIDENCE LEVELS AND FIND THE NUM STD DEVIATIONS FOR
  * THAT CONFIDENCE LEVEL */
  int i;
  for (i = 0; i < (sizeof(confidence_level_constant)/sizeof(float)/2); i++)
  {
    if (confidence_level_constant[i][0] == confidence_level)
    {
      Z = confidence_level_constant[i][1];
    }
  }
  if (Z == 0.0)
  {
    return -1;
  }
 
  /* CALC SAMPLE SIZE */
  n_0 = (pow(Z, 2) * p * (1-p))/pow(e, 2);
  /* ADJUST SAMPLE SIZE FOR FINITE POPULATION */
  n = n_0 / (1 + ((n_0 - 1)/(float)N));
 
  return ceil(n); /* THE SAMPLE SIZE */
}
 
int main()
{
  int sample_sz;
  long long population_sz = 1000000;
  float confidence_level = 95.0;
  float confidence_interval = 2.0;
 
  sample_sz = sample_size(population_sz, confidence_level, confidence_interval);
 
  printf("SAMPLE SIZE: %d\n", sample_sz);
 
  return 0;
}
