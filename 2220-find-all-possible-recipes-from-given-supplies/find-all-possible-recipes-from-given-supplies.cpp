class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
         unordered_map<string, int> inDegree;  // Store the number of missing ingredients for each recipe
        unordered_map<string, vector<string>> graph;  // Map ingredients to recipes that depend on them
        unordered_set<string> available(supplies.begin(), supplies.end());  // Store available supplies
        queue<string> q;
        
        // Initialize graph and in-degree map
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);  // "ing" is used to make "recipes[i]"
            }
        }
        
        // Start with available supplies
        for (string& item : supplies) {
            q.push(item);
        }
        
        vector<string> result;
        
        while (!q.empty()) {
            string item = q.front();
            q.pop();
            
            // If this item is a recipe, add it to the result
            if (inDegree.count(item)) {
                result.push_back(item);
            }
            
            // Reduce in-degree of recipes that depend on this ingredient
            for (string& dependentRecipe : graph[item]) {
                if (--inDegree[dependentRecipe] == 0) {
                    q.push(dependentRecipe);
                }
            }
        }
        
        return result;
    }
};