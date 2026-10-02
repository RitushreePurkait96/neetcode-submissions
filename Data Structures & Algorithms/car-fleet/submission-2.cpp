/*
The Solution: Sort + Monotonic Stack
To solve this cleanly, we process cars from closest to the target to farthest from the target (descending order of position).

Pair each car's position and speed, then sort them by position in descending order.

Iterate through them, calculating each car's individual arrival time (double).

Use a stack to track the fleet times:

If the current car takes more time than the car (or fleet) ahead of it (time > st.top()), it means it can never catch up to them. It must form a new fleet, so we push its time to the stack.

If it takes less or equal time, it catches up and merges into the fleet ahead of it. We don't push anything.

The size of the stack at the end is our total number of fleets!
*/


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        // Sort cars by position in descending order (closest to target first)
        sort(cars.rbegin(), cars.rend());
        
        stack<double> st;
        
        for (auto& car : cars) {
            // Calculate exact time using double to prevent truncation
            double time = (double)(target - car.first) / car.second;
            
            // If stack is empty, or this car takes MORE time than the fleet ahead,
            // it cannot catch them up -> it forms a new fleet.
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // Otherwise, it merges into the fleet ahead of it (do nothing).
        }
        
        return st.size();
    }
};