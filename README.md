# fractol

Fractol is a program developped for my learning course at 42 school for the exploration of fractals.
<img align="center" src="http://image.noelshack.com/fichiers/2016/25/1466426395-screen-shot-2016-06-20-at-2-38-21-pm.png" width="100%" />
Several options are available (see [Keyboard shortcuts](https://github.com/Kikoman90/fractol#keyboard-shortcuts) and/or [Mouse controls](https://github.com/Kikoman90/fractol#mouse-controls) sections for more infos) :
* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Edit the display color gradient
* Increase/decrease color frequency
* Navigate between the three fractals
* Edit the shape of the fractal with mouse motion (only available with the fractal Julia)

## Install & launch
```bash
git clone https://github.com/Kikoman90/fractol ~/fractol
cd ~/fractol && ./fractol 2
```
You have to launch the program with a parameter. 1 for Julia, 2 for Mandlebrot, 3 for Tricorn.
Example :

Open the Mandelbrot fractal ⇣
```bash
./fractol 3
```
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the display color gradient (change color)</td>
<td valign="top" align="center"><kbd>&nbsp;C&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase/decrease color frequency factor</td>
<td valign="top" align="center"><kbd>&nbsp;D&nbsp;</kbd> <kbd>&nbsp;F&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable mouse motion (for Julia fractal only)</td>
<td valign="top" align="center"><kbd>&nbsp;A&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal up/down</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd> <kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the left/right</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd> <kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase/decrease the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd> <kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch between predefined Julia parameters</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch between fractals</td>
<td valign="top" align="center"><kbd>&nbsp;S&nbsp;</kdb></td>
</tr>
</tbody>
</table>
## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;left button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;right button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal (zoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal (unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Contact & contribute
If you want to contact me, or fix/improve Fractol, just send me a mail at **fsidler@student.42.fr**
