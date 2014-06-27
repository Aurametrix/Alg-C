function sample() {
  var bestCandidate, bestDistance = 0;
  for (var i = 0; i < numCandidates; ++i) {
    var c = [Math.random() * width, Math.random() * height],
        d = distance(findClosest(samples, c), c);
    if (d > bestDistance) {
      bestDistance = d;
      bestCandidate = c;
    }
  }
  return bestCandidate;
}

