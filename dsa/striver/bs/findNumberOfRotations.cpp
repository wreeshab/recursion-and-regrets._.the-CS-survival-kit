The number of rotations is equal to the **index of the minimum element**

find mid, compare with mid + 1 and mid -1  return if found or prune the search space.


if (arr[mid] >= arr[low]) {
            low = mid + 1;  // minimum is in the right half
        } else {
            high = mid - 1; // minimum is in the left half
        }
