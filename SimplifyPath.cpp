class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        char str[size + 1];
        strcpy(str, path.c_str());
        char *p = strtok(str, "/");
        
        stack<string> S;
        while(p) {
            if(strcmp(p, ".") == 0) {
                p = strtok(NULL, "/");
                continue;
            }
            if(strcmp(p, "..") == 0) {
                if(!S.empty())
                    S.pop();
                p = strtok(NULL, "/");
                continue;
            }
            if(strcmp(p, "") == 0) {
                p = strtok(NULL, "/");
                continue;
            }
            string temp(p);
            S.push(temp);
            p = strtok(NULL, "/");
        }
        string res;
        if(S.empty()) {
            res.insert(res.begin(), '/');
            return res;
        }
        
        while(!S.empty()) {
            string t = S.top();
            res.insert(res.begin(), t.begin(), t.end());
            res.insert(res.begin(), '/');
            S.pop();
        }
        
        return res;
        
    }
};
