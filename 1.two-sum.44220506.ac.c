/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void hash_init(int* hash, int* data, int prime){
    int i;
    for (i = 0; i < prime; i++) {
        hash[i] = 0;
        data[i] = 0;
    }
}
void hash_add(int* hash, int* data, int x, int idx, int prime){
    int i = (x+prime)%prime;
    while (hash[i] != 0) i=(i+1)%prime;
    hash[i] = idx; data[i] = x;
}
int hash_find(int *hash, int* data, int x, int idx, int prime){
    int i = (x+prime)%prime;
    while (hash[i]!=0){
        if (hash[i]!=idx && data[i]==x) return hash[i];
        i=(i+1)%prime;
    }
    return 0;
}
int* twoSum(int* nums, int numsSize, int target) {
    int P = 99983;
    int *index = malloc(sizeof(int)*2);
    int *hash = malloc(sizeof(int)*P);
    int *data = malloc(sizeof(int)*P);    
    int i,j;
    hash_init(hash, data, P);
    for (i = 0; i < numsSize; i++) hash_add(hash, data, nums[i], i+1, P);
    for (i = 0; i < numsSize; i++){
        int idx = hash_find(hash, data, target-nums[i], i+1, P);
        if (idx != 0){
            index[0]=i+1;
            index[1]=idx;
            free(hash);
            free(data);
            return index;
        }
    }
}
