void
bstack(Monitor *m)
{
  unsigned int i, n, w, mh, mx, tx;
  float mfacts = 0, sfacts = 0;
  Client *c;

  for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++) {
    if (n < m->nmaster)
      mfacts += c->cfact;
    else
      sfacts += c->cfact;
  }

  if (n == 0)
    return;

  if(n == 1){
    c = nexttiled(m->clients);
    resize(c, m->wx + m->gappx, m->wy + m->gappx, m->ww - 2 * c->bw - m->gappx * 2, m->wh - 2 * c->bw - m->gappx * 2, 0);
    return;
  }

  if (n > m->nmaster) {
    mh = m->nmaster ? m->wh * m->mfact : 0;
  } else {
    mh = m->wh;
  }

  for (i = 0, mx = tx = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++)
  {
    if (i < m->nmaster) {
      w = (m->ww - mx) * (c->cfact / mfacts) - m->gappx;
      resize(c, m->wx + mx, m->wy, w - (2*c->bw) + (m->gappx / 2), mh - 2*c->bw, 0);
      //mx += WIDTH(c) + m->gappx;
      mx += w - (2*c->bw) + m->gappx;
      mfacts -= c->cfact;
    } else {
      w = (m->ww - tx) * (c->cfact / sfacts) - m->gappx;
      resize(c, m->wx + tx, m->wy + mh - m->gappx, w - (2*c->bw), m->wh - mh - 2*(c->bw) + m->gappx, 0);
      //tx += WIDTH(c) + m->gappx;
      tx += w - (2*c->bw) + m->gappx;
      sfacts -= c->cfact;
    }
  }
}

void
bstackhoriz(Monitor *m)
{
  unsigned int i, n, h, mw, mh, my, ty;
  float mfacts = 0, sfacts = 0;
  Client *c;

  for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++) {
    if (n < m->nmaster)
      mfacts += c->cfact;
    else
      sfacts += c->cfact;
  }

  if (n == 0)
    return;

  if(n == 1){
    c = nexttiled(m->clients);
    resize(c, m->wx, m->wy, m->ww - 2 * c->bw, m->wh - 2 * c->bw, 0);
    return;
  }

  if (n > m->nmaster) {
    mh = m->nmaster ? m->wh * m->mfact : 0;
  } else {
    mh = m->wh;
  }

  mw = m->ww;

  for (i = ty = 0, my = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
    if (i < m->nmaster) {
      h = (mh - my) * (c->cfact / mfacts) - m->gappx;
      resize(c, m->wx, m->wy + my, mw - 2*c->bw, h - 2*c->bw, 0);
      my += HEIGHT(c) + m->gappx;
      mfacts -= c->cfact;
    } else {
      h = (m->wh - mh - ty) * (c->cfact / sfacts) - m->gappx;
      resize(c, m->wx, m->wy + mh + ty, mw - 2*c->bw, h - (2*c->bw), 0);
      ty += HEIGHT(c) + m->gappx;
      sfacts -= c->cfact;
    }
  }
}
