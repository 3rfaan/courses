import { Form, Input, Modal } from "antd";
import { EyeInvisibleOutlined, EyeTwoTone } from "@ant-design/icons";

interface Props {
    shouldShowMedal: boolean;
    onSubmit: (token: string) => void;
    onCancel: () => void;
}

const AuthModal: React.FC<Props> = ({
    shouldShowMedal, onSubmit, onCancel
}) => {
    const [form] = Form.useForm();

    const onFormSubmit = () => {
        form.validateFields().then((values) => {
            onSubmit(values.token);
        });
    }

    return (
        <Modal
            title="Provide Github Authentication Token"
            centered okText="Save"
            cancelText="Cancel"
            open={shouldShowMedal}
            onOk={onFormSubmit}
            onCancel={onCancel}>
            <Form
                form={form}
                name="auth_form"
                initialValues={{ token: "" }}>
                <Form.Item
                    name="token"
                    label="token"
                    rules={[{ required: true, message: "Please provide your Github Token!" }]}>
                    <Input.Password
                        placeholder="Github Token"
                        iconRender={(visible) =>
                            visible ? <EyeTwoTone /> : <EyeInvisibleOutlined />}
                    />
                </Form.Item>
            </Form>
        </Modal>
    );
};

export default AuthModal;
