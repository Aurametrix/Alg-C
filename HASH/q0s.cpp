void Queue::enqueue(int value) {
  stack.push(value);
}

int Queue::dequeue() {
  // TODO: Check for empty queue.
  Stack tempStack;
  do {
    tempStack.push(stack.pop());
  } while (!stack.empty());
  int value = tempStack.pop();
  while (!tempStack.empty()) {
    stack.push(tempStack.pop());
  }
  return value;
}
