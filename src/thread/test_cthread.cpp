#include "cthread.h"
using namespace std;

void* sum(void *arg) {
    int* nums = (int*)arg;
    int* result = new int;
    *result = 0;
    int num_len = sizeof(nums) / sizeof(nums[0]);
    for(int i=0; i < num_len; ++i) {
        *result += nums[i];
    }
    cout << "sum func" << endl;
    pthread_exit((void *)result);
}

int main(int argc, char *argv[]) {
    int nums[] = {1, 2, 3, 4};
    Cthread cthread = Cthread(&sum, (void *)&nums);
    cthread.Start();
    void* result_ptr;
    cthread.Join(&result_ptr);
    cout << "sum result:" << *(int*)result_ptr << endl;
    delete (int *)result_ptr;
}
