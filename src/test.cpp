#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinaryTree.h"

using namespace std;
// DO NOT MAKE CHANGES TO CAPTUREOUTPUT FUNCTION //
inline string captureOutput(function<void()> func) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(sbuf);
    return buffer.str();
}

/**
 * helper for printout
*/
static void printOutput(vector<vector<int>>& allLayers) {
    cout<<"Depth: "<< allLayers.size() << endl;
    cout<<"[";
    for (auto layer : allLayers) {
        cout<<"[";
        for (int idex = 0; idex < layer.size(); idex++) {
            cout<< layer.at(idex);
            if (idex != (layer.size() -1)) cout << ",";
        }
        cout<<"]";
    }
    cout<<"]\n";
}

/**
 * compare vector
*/
static bool compareVector(vector<vector<int>>& vector1, vector<vector<int>>& vector2) {
    if (vector1.size() != vector2.size()) return false;
    for (int layer = 0; layer < vector1.size(); layer++) {
        for (int nodeIdx = 0; nodeIdx < vector1.at(layer).size(); nodeIdx++) {
            if (vector1.at(layer).at(nodeIdx) != vector2.at(layer).at(nodeIdx)) return false;
        }
    }
    return true;
}

static void test() {
  /**
   * test case 1
  */
  {
    cout<<"===============TEST 1 START================="<< endl;
    cout<<"Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]"<< endl;
    cout<<"Output: [3,9,20,null,null,15,7]"<< endl;
    string expected ="3 9 20 15 7 ";
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = solution.buildTree(preorder, inorder);
    std::string output = captureOutput([&]() {
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }
  /**
   * test case 2
  */
  {
    cout<<"===============TEST 2 START================="<< endl;
    cout<<"Input: preorder = [1, 2, 4, 5, 3, 6, 7, 8], inorder = [4, 2, 5, 1, 7, 6, 8, 3]"<< endl;
    string expected ="1 2 4 5 3 6 7 8 ";
    Solution solution;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7, 8};
    vector<int> inorder = {4, 2, 5, 1, 7, 6, 8, 3};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }
  /**
   * test case 3
  */
  {
    cout<<"===============TEST 3 START================="<< endl;
    cout<<"Input: preorder = [-1], inorder = [-1]"<< endl;
    string expected ="-1 ";
    Solution solution;
    vector<int> preorder = {-1};
    vector<int> inorder = {-1};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }

    /**
   * test case 4
  */
  {
    cout<<"===============TEST 3 START================="<< endl;
    cout<<"Input: preorder = [1, 2], inorder = [2, 1]"<< endl;
    string expected ="1 2 ";
    Solution solution;
    vector<int> preorder = {1, 2};
    vector<int> inorder = {2, 1};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }


    /**
   * test case 4
  */
  {
    cout<<"===============TEST 4 START================="<< endl;
    cout<<"Input: preorder = [1, 2], inorder = [1, 2]"<< endl;
    string expected ="1 2 ";
    Solution solution;
    vector<int> preorder = {1, 2};
    vector<int> inorder = {1, 2};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }
  /**
   * test case 5
  */
  {
    cout<<"===============TEST 5 START================="<< endl;
    cout<<"Input: preorder = [1, 2, 3], inorder = [3, 2, 1]"<< endl;
    string expected ="1 2 3 ";
    Solution solution;
    vector<int> preorder = {1, 2, 3};
    vector<int> inorder = {3, 2, 1};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }

    /**
   * test case 6
  */
  {
    cout<<"===============TEST 6 START================="<< endl;
    cout<<"Input: preorder = [1, 2, 3], inorder = [2, 3, 1]"<< endl;
    string expected ="1 2 3 ";
    Solution solution;
    vector<int> preorder = {1, 2, 3};
    vector<int> inorder = {2, 3, 1};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }

    /**
   * test case 7
  */
  {
    cout<<"===============TEST 7 START================="<< endl;
    cout<<"Input: preorder = [1, 2, 3], inorder = [1, 2, 3]"<< endl;
    string expected ="1 2 3 ";
    Solution solution;
    vector<int> preorder = {1, 2, 3};
    vector<int> inorder = {1, 2, 3};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(preorder, inorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }

}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


