#!/bin/bash

./dijkstra.out
dot -Tpdf graph.dot -o graph.pdf
rm graph.dot
