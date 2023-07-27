#include <stdio.h>

int sum(int const *const ptr, int n) {
    // Write your code here
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        // Closely observe this scanf statement
        // [] or & are not required; and still it works as expected
        // Scans elements into arr
        scanf("%d", arr + i);
    }
    
    int result = sum(arr, n);
    printf("%d", result);
    
    return 0;
}
