import { Button, Result } from "antd";
import React, { createContext, useContext, useEffect, useState } from "react";
import AuthModal from "./AuthModal";
import { useNavigate } from "react-router-dom";
import { Nullable } from "../../types";

type AuthContextType = {
    token: Nullable<string>;
};

const AuthContext = createContext<AuthContextType>({ token: null });

interface Props {
    children: React.ReactNode;
}

const AuthContextProvider: React.FC<Props> = ({ children }) => {
    const [token, setToken] = useState<Nullable<string>>(null);
    const [shouldShowModal, setShouldShowModal] = useState(true);

    const navigate = useNavigate();

    useEffect(() => {
        const timer = setTimeout(() => {
            if (token !== null) {
                setToken(null);
                setShouldShowModal(true);
            }
        }, 3_600_000);
        return () => clearTimeout(timer);
    }, [token]);

    const onSubmit = (token: string) => {
        setToken(token);
        setShouldShowModal(false);
    };

    const onCancel = () => {
        setShouldShowModal(false);
    };

    if (!shouldShowModal && !token) {
        return (
            <Result
                status="error"
                title="Authentication Failed"
                subTitle="A Github token is required to view this page"
                extra={[
                    <Button
                        type="link"
                        key="home"
                        onClick={() => navigate("/")}
                    >
                        Public Section
                    </Button>,
                    <Button
                        key="retry"
                        type="primary"
                        onClick={() => setShouldShowModal(true)}
                    >
                        Try Again
                    </Button>
                ]}
            />
        );
    }

    return (
        <>
            {shouldShowModal && (
                <AuthModal
                    shouldShowMedal={shouldShowModal}
                    onSubmit={onSubmit}
                    onCancel={onCancel}
                />
            )}
            <AuthContext.Provider value={{ token }}>{children}</AuthContext.Provider>
        </>
    );
};

export const useAuthContext = () => {
    const context = useContext(AuthContext);
    if (context === undefined) {
        throw new Error("useAuthContext must be used within a AuthContextProvider");
    }
    return context;
};

export default AuthContextProvider;
