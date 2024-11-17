#include <iostream>

#include "constants.hpp"
#include "return_node.hpp"

ReturnNode::ReturnNode(ExpressionNode* return_exp) : ExpressionNode() {
  this->return_exp = return_exp;
}

Value ReturnNode::GetValue(Context* context) {
  if (this->return_exp == nullptr) {
    return Value();
  }
  return this->return_exp->GetValue(context);
}

void ReturnNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }

  std::cout << "return: ";
  if (this->return_exp == nullptr) {
    std::cout << "<void>";
  }
  std::cout << std::endl;
  if (this->return_exp != nullptr) {
    this->return_exp->Print(indent + 1);
  }
}

void ReturnNode::Execute(Context* context) {
  throw this->GetValue(context);
}
