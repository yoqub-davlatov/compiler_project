#pragma once

#include "blocks_node.hpp"
#include "expression_node.hpp"

struct Parameters : public Node {
  std::vector<std::string> parameters;

  Parameters();

  void Add(std::string&& parameter);
};

struct FunctionNode : public ExpressionNode {
  Value result;
  std::vector<std::string> parameters;
  BlocksNode* body;
  Context context;
  
  FunctionNode(BlocksNode* body, Parameters* parameters);

  void Execute(Context* context, const bool dry_run) override;
  void Optimize() override;

  void Print(int indent) override;

  Value GetValue(Context* context) override;
};