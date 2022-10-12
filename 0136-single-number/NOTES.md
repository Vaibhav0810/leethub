[https://leetcode.com/problems/single-number/discuss/1772139/C%2B%2Bor-Explained-Everything-w-WHY-XOR-WORKSor-BRUTE-FORCE-TO-OPTIMIZEDor-STEP-BY-STEP-DRY-RUN](http://)
​
Solution - II (using property of xor, Accepted)-
​
Now, the question arises, is their any way so that we do not need to store frequency, i.e
can we space optimized our answer?
Since, we want not to use map, so we will see our map that where is the problem?
We observe a very basic thing that other than our answer, frequency of each element is 2, that means our question wants to say that, every element appears twice except the single one and we have to find that particular single element.
So, if every element appears twice, do we really need to store the frequency of each element?
Answer is No, we do not need to store the frequency of each element because we already know that, for each element their is only two ways, either it's frequency is 1 or it's frequency is 2. Their is not any third option other than that.
In this way, we can think of the property of XOR-
0 ^ 0 --> 0
0 ^ 1 --> 1
1 ^ 0 --> 1
1 ^ 1 --> 0
If we see, we will find out that xor of two same number is zero.
Can we use this property here?
Answer is Yes. But how?
We will run a loop from all over the array, and simply start taking xor of two.
We do xor between prev answer of xor and current element.
See dry run for more clarification.
But, Question is WHY? why this works?
We know every number is appears twice except a single number which appears only single time.
​
See, we already discuss a thing a that xor of a same number with itself is zero, i.e A ^ A = 0
Now, we will look some more property of xor-
​
1) xor of a same number with itself is zero, i.e A ^ A = 0
2) xor is commutative that means a ^ b = b ^ a.
3) xor of any number with zero is the number itself i.e A ^ 0 = A.
​
Suppose our array is arr[]: [5, 1, 3, 1, 3, 4, 5, 7, 4]
we will rearrange the array, and take all the numbers together, then our array looks like
arr[]: [1, 1, 3, 3, 4, 4, 5, 5, 7]
now, take xor of all numbers -
1 ^ 1 ^ 3 ^ 3 ^ 4 ^ 4 ^ 5 ^ 5 ^ 7   (rearrange the array)
0   ^   0   ^   0   ^   0   ^ 7   (see point number 1)
7                     (see point number 3)
​
Now, The question again arises, do we really need to rearrange the array ?
Answer is NO.
1 ^ 5 = 4 (prev answer xor current index)