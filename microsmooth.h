#ifndef MICROSMOOTH
#define MICROSMOOTH

#define SMA 0b00000001
#define CMA 0b00000010
#define EMA 0b00000100
#define SGA 0b00001000
#define KZF 0b00010000
#define RDP 0b00100000

#define SMA_LENGTH 43
#define EMA_ALPHA 0.10
#define SG_LENGTH 11
#define RDP_LENGTH 11
#define epsilon 50
#define KZ_LENGTH 5
#define KZ_MAX 4
#define KZ_history_LENGTH ((KZ_LENGTH-1)*KZ_MAX)


extern int history_SMA[SMA_LENGTH];
extern int history_SG[SG_LENGTH];
extern int history_KZ[KZ_history_LENGTH];
extern int history_RDP[RDP_LENGTH];
extern int index_RDP[];


int* init();
int simple_mov_avg(int current_value);
int cumulative_mov_avg(int current_value);
int exponential_mov_avg(int current_value);
int savitzky_golay(int current_value);
int KZ_filter(int current_value);
int RDP_caller(int current_value);
int deinit();


#endif
