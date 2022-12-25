const ans = [];
const solve = (arr, n, sum, count, subArr) => {
  if (count == 3 && sum == 0) {
    ans.push(Array.from(subArr));
    return;
  }

  if (count == 3 || n == 0 || sum < 0)
    return;

  subArr.unshift(arr[n-1]);
  solve(arr, n - 1, sum - arr[n-1], count + 1, subArr);
  subArr.shift();

  solve(arr, n-1, sum, count, subArr);

}
const arr = [2, 7, 4, 0, 9, 5, 1, 3];
const target = 6;
solve(arr, arr.length,target, 0, []);
console.log(ans);