// Copyright 2019 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PLANSYS2_CORE__TYPES_HPP_
#define PLANSYS2_CORE__TYPES_HPP_

#include <string>
#include <vector>

#include "plansys2_msgs/msg/node.hpp"
#include "plansys2_msgs/msg/param.hpp"
#include "plansys2_msgs/msg/tree.hpp"

#include "plansys2_pddl_parser/Utils.h"

namespace plansys2
{

struct PlanItem
{
  float time;
  std::string action;
  float duration;
};

typedef std::vector<PlanItem> Plan;

class Instance : public plansys2_msgs::msg::Param
{
public:
  explicit Instance(const std::string & name, const std::string & type = {})
  : plansys2_msgs::msg::Param(parser::pddl::fromStringParam(name, type)) {}
  explicit Instance(const plansys2_msgs::msg::Param & instance)
  : plansys2_msgs::msg::Param(instance) {}
};

class Predicate : public plansys2_msgs::msg::Node
{
public:
  explicit Predicate(const std::string & pred)
  : plansys2_msgs::msg::Node(parser::pddl::fromStringPredicate(pred)) {}
  explicit Predicate(const plansys2_msgs::msg::Node & pred)
  : plansys2_msgs::msg::Node(pred) {}
};

class Function : public plansys2_msgs::msg::Node
{
public:
  explicit Function(const std::string & func)
  : plansys2_msgs::msg::Node(parser::pddl::fromStringFunction(func)) {}
  explicit Function(const plansys2_msgs::msg::Node & func)
  : plansys2_msgs::msg::Node(func) {}
};

class Goal : public plansys2_msgs::msg::Tree
{
public:
  explicit Goal(const std::string & goal)
  : plansys2_msgs::msg::Tree(parser::pddl::fromString(goal)) {}
  explicit Goal(const plansys2_msgs::msg::Tree & goal)
  : plansys2_msgs::msg::Tree(goal) {}
};

}  // namespace plansys2

#endif  // PLANSYS2_CORE__TYPES_HPP_
