/*******************************************************************************
 * Copyright 2019-2020 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#include "tensorflow/core/lib/core/errors.h"

#include "ngraph/ngraph.hpp"
#include "ngraph/runtime/backend_manager.hpp"
#include "ngraph_catalog.h"
#include "ngraph_log.h"

using namespace std;
namespace ng = ngraph;

namespace tensorflow {

namespace ngraph_bridge {

template <class K, class V, class Hash, class KeyEqual, class Allocator>
void CatalogBase<K, V, Hash, KeyEqual, Allocator>::AddToCatalog(V val, K key) {
  this->insert({key, val});
}

template <class K, class V, class Hash, class KeyEqual, class Allocator>
bool CatalogBase<K, V, Hash, KeyEqual, Allocator>::ExistsInCatalog(K key) {
  return this->find(key) != this->end();
}

CatalogBase<TensorID, string, TensorID::TensorIDHash> NGraphCatalog::catalog1;

/*
// TODO remove this block showing sample usage
void f() {
  TensorID x("xx", false, 1);
  std::cout << x.to_string() << "\n";

  NGraphCatalog::catalog1.AddToCatalog("hello", x);
  NGraphCatalog::catalog1[x] = "bye";
}*/

}  // ngraph_bridge
}  // tensorflow