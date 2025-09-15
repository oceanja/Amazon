*********************************BRUTE***********************************************
 Problem restate
We need a stack that supports the usual push, pop, and top operations, but also an additional operation getMin() 
that returns the minimum element in the stack, all in O(1) time.

Naïve thinking (why it doesn’t work well)
The simplest idea would be: whenever getMin() is called, scan the whole stack to find the minimum.
But that takes O(n) each time, which is inefficient if getMin() is called frequently.

So I needed a way to always know the minimum at the current state of the stack without scanning.

Key idea
Instead of storing just the value, I’ll store extra information with each element.

For every element pushed, I’ll also store the minimum value of the stack up to this element.

This way, the top of the stack always knows what the minimum is at that level.

That means I don’t need to search — getMin() just looks at the second value in the top pair.

How operations work in my code

push(val):

If the stack is empty, that value is the min by default. Push (val, val).

Otherwise, take the current global min as st.top().second. Compare with val and store the smaller. Push (val, min(val, st.top().second)).

pop():

Just pop from the stack as usual. Since each node carries its own “min so far,” popping automatically restores the correct minimum.

top():

Return st.top().first (the actual value).

getMin():

Return st.top().second (the minimum stored alongside the top element).

Complexity analysis

Time:

push: O(1) (just compare and push).

pop: O(1).

top: O(1).

getMin: O(1).

Space: O(n), since we’re storing one extra integer (the running min) per element.



class MinStack {
public:
 stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

*********************************************** OPTIMAL ********************************************
1. High-Level Overview

The idea behind this MinStack is to design a stack that can return the minimum element in O(1), 
alongside the usual push, pop, and top operations.
Instead of storing just values, we encode values when they’re smaller than the current minimum, 
so we can restore the previous minimum later when popping.

2. Data Structures and Algorithm Choice

Stack (st): holds either the actual value or an encoded value when a new minimum is pushed.

Variable (mini): tracks the current minimum.

Why this works:

Normally, a stack only gives LIFO order, but we need the min across all elements.

A second stack for minimums is common, but this solution is more space-efficient: it uses clever encoding 
(storing 2*val - mini) to remember history without an extra stack.

Trade-off: adds a bit of arithmetic complexity but saves space.

3. Step-by-Step Walkthrough

Let’s dry run with input sequence:
push(5), push(3), push(7), getMin(), pop(), getMin()

Start

Stack: empty

mini = ∞

push(5)

Empty stack → set mini = 5, push 5.

Stack: [5], mini = 5.

push(3)

3 < mini (5), so encode: (2*3 - 5) = 1. Push 1.

Update mini = 3.

Stack: [5, 1], mini = 3.

push(7)

7 > mini (3), push as is.

Stack: [5, 1, 7], mini = 3.

getMin()

Return mini = 3.

pop()

Top = 7. Since 7 > mini (3), normal pop.

Stack: [5, 1], mini = 3.

getMin()

Return mini = 3.

Now let’s pop once more:

pop() (removes 1)

Top = 1, which is < mini (3). That means 1 was an encoded value.

Restore old minimum: mini = 2*mini - top = 2*3 - 1 = 5.

Pop it.

Stack: [5], mini = 5.

So we successfully tracked the min through encoding.

4. Complexity Analysis

Time:

push, pop, top, getMin → O(1) each.

Space:

O(n) for stack + O(1) extra (mini).

More space-efficient than the "two stacks" method.

5. Potential Improvements / Edge Cases

Empty stack: top returns -1, getMin just returns mini. Could throw an exception or handle explicitly.

Large values: Works fine since we use long long to prevent overflow when calculating (2*val - mini).

Alternative: Using two stacks (main + minStack) is simpler and less error-prone, but doubles memory usage.

Optimization: If interviewer prioritizes readability over space, two-stack approach might be preferred. 
This encoded trick is more "clever" but harder to maintain.



class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;  
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val > mini) {
                st.push(val);
            } else {
                st.push((2LL * val) - mini); 
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }

        long long x = st.top();
        st.pop();
        if (x < mini) {
            mini = (2LL * mini) - x; 
        }
    }
    
    int top() {
        if (st.empty()) {
            return -1;
        }

        long long x = st.top();
        if (x > mini) {
            return x;
        } else {
            return mini; 
        }
    }
    
    int getMin() {
        return mini;  
    }
};
