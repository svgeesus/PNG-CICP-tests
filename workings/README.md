# Colorspace conversions

Converted [from sRGB](../README.md) to destination [using color.js](https://colorjs.io/apps/convert/?color=rgb(199%20148%20129)&precision=5) and coordinates rounded to [0,255].

## Display p3

<table>
<tr>
<td>dark skin<br>color(display-p3 0.43827 0.32728 0.27227)<br>[112, 83, 69]</td>
<td>light skin<br>color(display-p3 0.74986 0.58848 0.518)<br>[191, 150, 132]</td>
<td>blue sky<br>color(display-p3 0.38292 0.47883 0.6039)<br>[98, 122, 154]</td>
<td>foliage<br>color(display-p3 0.36363 0.42131 0.27327)<br>[93, 107, 70]</td>
<td>blue flower</br>color(display-p3 0.51234 0.50615 0.67637)<br>[131, 129, 172]</td>
<td>bluish green<br>color(display-p3 0.46549 0.73637 0.67618)<br>[119, 188, 172]</td>
</tr>
<tr>
<td>orange<br>color(display-p3 0.82251 0.50571 0.24813)<br>[210, 129, 63]</td>
<td>purplish blue<br>color(display-p3 0.28908 0.35822 0.63846)<br>[74, 91, 163]</td>
<td>moderate red<br>color(display-p3 0.72925 0.3573 0.38876)<br>[186, 91, 99]</td>
<td>purple<br>color(display-p3 0.34201 0.23703 0.39738)<br>[87, 60, 101]</td>
<td>yellow green</br>color(display-p3 0.64646 0.73766 0.32827)<br>[165, 188, 84]</td>
<td>orange yellow<br>color(display-p3 0.86577 0.64673 0.26777)<br>[221, 165, 68]</td>
</tr>
<tr>
<td>blue<br>color(display-p3 0.17274 0.24074 0.55592)<br>[44, 61, 142]</td>
<td>green<br>color(display-p3 0.34706 0.57321 0.31911)<br>[89, 146, 81]</td>
<td>red<br>color(display-p3 0.65731 0.22642 0.2374)<br>[168, 58, 61]</td>
<td>yellow<br>color(display-p3 0.91588 0.79019 0.28062)<br>[234, 201, 72]</td>
<td>magenta</br>color(display-p3 0.70444 0.35488 0.57413)<br>[180, 90, 146]</td>
<td>desat_cyan<br>color(display-p3 0.22558 0.51352 0.6156)<br>[58, 131, 157]</td>
</tr>
<tr>
<td>white 9.5<br>color(display-p3 0.96078 0.96078 0.94295)<br>[245, 245, 240]</td>
<td>neutral 8<br>color(display-p3 0.78501 0.78811 0.78817)<br>[200, 201, 201]</td>
<td>neutral 6.5<br>color(display-p3 0.62815 0.63124 0.63131)<br>[160, 161, 161]</td>
<td>neutral 5<br>color(display-p3 0.47129 0.47438 0.47444)<br>[120, 121, 121]</td>
<td>neutral 3.5<br>color(display-p3 0.32619 0.32928 0.33292)<br>[83, 84, 85]</td>
<td>black 2<br>color(display-p3 0.19608 0.19608 0.19608)<br>[50, 50, 50]</td>
</tr>
</table>

## Making the images

A quick and dirty [C program](./macbeth.c) loops over the patch color data
(from either [srgb.h](./srgb.h) or [display-p3.h](display-p3.h))
and spits out an [ascii PPM file](https://netpbm.sourceforge.net/doc/ppm.html).

This is then converted to PNG with
[pnmtopng](https://netpbm.sourceforge.net/doc/pnmtopng.html):

```bash
pnmtopng -verbose tmp.ppm > tmp.png
```

![srgb](./img/macbeth-srgb.png)

For the display-p3 image, a `cICP` chunk is added with
[`png_cicp_editor](https://github.com/ProgramMax/png_cicp_editor):

```bash
png_cicp_editor add --preset display-p3 macbeth-display-p3.png
```

![display p3](./img/macbeth-display-p3.png)
