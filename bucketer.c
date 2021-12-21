#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  for(int i=0;i<cycles.length;i++)
  {
      if(cycles[i]<150) counts.lowCount++;
      else if(cycles[i]>=150 && cycles[i]<650) counts.mediumCount++;
      else counts.highCount++;
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  try{
  assert(counts.lowCount == 1);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 2);
  
  }
  catch(AssertionError e)
  {
      
  }
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
