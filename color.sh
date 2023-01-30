#!/bin/bash

echo "t_color color_palette[256] = {"

for i in {0..255}
do
    echo "    {255, $i, 0},"
done

echo "};"

