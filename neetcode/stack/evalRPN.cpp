class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<optional<int>(int, int)>> operandMap = {
            {"+", [](int a, int b) -> optional<int> { return a + b; }},
            {"-", [](int a, int b) -> optional<int> { return a - b; }},
            {"*", [](int a, int b) -> optional<int> { return a * b; }},
            {"/", [](int a, int b) -> optional<int> {
                if (b != 0) {
                    return a / b;
                }
                return nullopt;
            }}
        };

        for (const string& s : tokens) {
            if (auto it = operandMap.find(s); it != operandMap.end()) {
                if (st.size() >= 2) {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();

                    if (auto res = it->second(a, b)) {
                        st.push(*res);
                    }
                }
            } else {
                st.push(stoi(s));
            }
        }

        return st.empty() ? 0 : st.top();
    }
};
