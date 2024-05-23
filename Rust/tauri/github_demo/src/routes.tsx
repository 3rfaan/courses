import App from "./App";

import CreateGist from "./components/gist/CreateGist";
import PrivateGists from "./components/gist/PrivateGists";
import PublicGists from "./components/gist/PublicGists";

import PrivateRepositories from "./components/repository/PrivateRepositories";
import PublicRepositories from "./components/repository/PublicRepositories";
import AuthContextProvider from "./components/context/AuthContext";

const routes = [
    {
        path: "/",
        element: <App />,
        children: [
            { index: true, element: <PublicRepositories /> },
            { path: "repositories/public", element: <PublicRepositories /> },
            { path: "gists/public", element: <PublicGists /> },
            {
                path: "gist/new",
                element: (
                    <AuthContextProvider><CreateGist /></AuthContextProvider>
                ),
            },
            {
                path: "repositories/private",
                element: (
                    <AuthContextProvider><PrivateRepositories /></AuthContextProvider>
                ),
            },
            {
                path: "gists/private",
                element: (
                    <AuthContextProvider><PrivateGists /></AuthContextProvider>
                ),
            },
        ],
    },
];

export default routes;
