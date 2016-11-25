/* ----------------------------------------------------------------- */

#pragma once

#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>


#include "utils/exceptions.hpp"

namespace io {

  // write the graph g to the outstream "out"
  template<typename Graph, typename Vertex = typename Graph::Vertex, typename Edge = typename Graph::Edge>
  void write_edgelist(std::ostream& out, const Graph& g){
    for(auto ur = g.vertices(); ur.first != ur.second; ++ur.first){
      const Vertex& u = *ur.first;
      const size_t u_idx = g.get_index(u);
      for(auto vr = g.adjacent_vertices(u); vr.first != vr.second; ++vr.first){
        // only output edges from smaller to larger index
        const Vertex& v = *vr.first;
        const size_t v_idx = g.get_index(v);
        if(v_idx < u_idx) out <<v_idx<<" "<<u_idx<<std::endl;
      } // for
    }
  } // function
} // namespace
