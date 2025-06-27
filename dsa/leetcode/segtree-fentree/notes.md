keep this in mind,
if (r < ql || l > qr) return;
if (ql <= l && r <= qr) {
    do something.
}

so basically , our range is the one shrinking not the query range , dont fuck up the condition.
