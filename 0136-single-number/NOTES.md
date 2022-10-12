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
// traverse from the array