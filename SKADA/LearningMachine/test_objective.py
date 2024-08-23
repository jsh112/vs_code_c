import optuna
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.metrics import mean_squared_error
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

# Load and split the data
data = load_iris()
X_train, X_test, y_train, y_test = train_test_split(
    data.data, data.target, test_size=0.2, random_state=2023)


def objective(trial):
    params = {
        'n_estimators': trial.suggest_int('n_estimators', 100, 1000),
        'max_depth': trial.suggest_int('max_depth', 1, 10),
        'ccp_alpha': trial.suggest_discrete_uniform('ccp_alpha', 0.1, 1, 0.1),
        'random_state': 0
    }

    # Print the suggested hyperparameters
    for k, v in params.items():
        print(k, v)

    model = GradientBoostingRegressor(**params)
    model.fit(X_train, y_train)

    # Predict and evaluate the model
    y_pred = model.predict(X_test)
    score = mean_squared_error(y_test, y_pred)

    return score


# Create a study and optimize the objective function
study = optuna.create_study(direction='minimize')
study.optimize(objective, n_trials=30)

# Output the best hyperparameters
print("Best hyperparameters: ", study.best_params)


fig1 = optuna.visualization.plot_parallel_coordinate(study)
fig1.show()
