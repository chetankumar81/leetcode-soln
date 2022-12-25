import { MinPriorityQueue } from "@datastructures-js/priority-queue";

const getKLargestElements = (arr,n,k) => {
  const mp = new MinPriorityQueue();
  for (let i=0; i<n; i++) {
    mp.enqueue(arr[i]);

    if (mp.size() > k) {
      mp.dequeue();
    }
  }

  return mp.toArray();
}
const arr = [7,10,4,3,20,15];
const k = 3;
console.log(getKLargestElements(arr,arr.length,k));