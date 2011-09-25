void
sideemup(Monitor *m) {
	unsigned int n, cols, cn, cx, cy, cw, ch;
	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next))
		n++;
	if(n == 0)
		return;

	/* numer of columns */
  cols = n;

	/* window geometries */
	cw = cols ? m->ww / cols : m->ww;
  ch = m->wh;
	for(cn = 0, c = nexttiled(m->clients); c; cn++, c = nexttiled(c->next)) {
		cx = m->wx + cn*cw;
		cy = m->wy;
		resizeclient(c, cx, cy, cw - 2 * c->bw, ch - 2 * c->bw);
	}
}
