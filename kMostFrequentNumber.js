import { MinPriorityQueue } from "@datastructures-js/priority-queue";

const getKMostFrequentNumber = (arr, n, k) => {
  const map = new Map();
  for (let i=0; i<n; i++) {
    map.set(arr[i], map.get(arr[i]) + 1 || 1);
  }

  const mp = new MinPriorityQueue((obj) => obj.key);
  for (const [key, value] of map) {
    mp.enqueue({key: value, value: key});

    if (mp.size() > k) {
      mp.dequeue();
    }
  }

  console.log(mp.toArray());
}

const arr = [1,1,1,3,2,2,4];
const k = 2;
getKMostFrequentNumber(arr, arr.length, k);

