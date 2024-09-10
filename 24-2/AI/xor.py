import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# Define the dataset: 2-bit XOR inputs and their corresponding labels
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([0, 1, 1, 0])  # XOR outputs

# Build the neural network model
model = Sequential([
    # Hidden layer with 4 neurons and ReLU activation
    Dense(4, input_dim=2, activation='relu'),
    Dense(1, activation='sigmoid')  # Output layer with sigmoid activation
])

# Compile the model
model.compile(optimizer='adam', loss='binary_crossentropy',
              metrics=['accuracy'])

# Train the model
model.fit(X, y, epochs=1000, verbose=0)

# Evaluate the model
loss, accuracy = model.evaluate(X, y)
print(f"Accuracy: {accuracy * 100:.2f}%")

# Make predictions
predictions = model.predict(X)
print("Predictions:")
for i, pred in enumerate(predictions):
    print(f"Input: {X[i]}, Predicted: {round(pred[0])}, Actual: {y[i]}")
