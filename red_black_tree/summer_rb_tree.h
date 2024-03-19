// 
// Author        : summer
// Description   : Make a short description for your file
// 
// Revision      :
// Rev.    Date        Designer    Description
// 1.0     2024-03-19  summer      Initial version
// 

#pragma once

#define SUMMER_DEBUG

#ifdef SUMMER_DEBUG
#include <iostream>
#endif
#include <stdexcept>

namespace Summer {

enum class _rb_tree_color {
  _rb_tree_red = false,
  _rb_tree_black = true
};

template<typename T>
class _rb_tree_node {
  public:
  private:
    _rb_tree_node* parent;
    _rb_tree_node* left;
    _rb_tree_node* right;
    int key;
    T data;
};

template<typename T>
class _rb_tree {
  public:

  private:
};
}
