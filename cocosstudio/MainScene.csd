<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MainScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.2.9.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000">
        <Timeline ActionTag="2115505191" Property="Position">
          <PointFrame FrameIndex="0" X="486.7263" Y="408.2739">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="2115505191" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="2115505191" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="root" ActionTag="-2036315765" Tag="13" IconVisible="False" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="960" Scale9Height="640" ctype="PanelObjectData">
            <Size X="960.0000" Y="640.0000" />
            <Children>
              <AbstractNodeData Name="imgUserName" ActionTag="930305531" Tag="5" IconVisible="False" LeftMargin="126.7781" RightMargin="689.2219" TopMargin="211.3145" BottomMargin="390.6855" Scale9Width="144" Scale9Height="38" ctype="ImageViewObjectData">
                <Size X="144.0000" Y="38.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="198.7781" Y="409.6855" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2071" Y="0.6401" />
                <PreSize X="0.1500" Y="0.0594" />
                <FileData Type="Normal" Path="Login/login_account.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgServer" ActionTag="213785901" Tag="6" IconVisible="False" LeftMargin="123.9550" RightMargin="692.0450" TopMargin="305.8837" BottomMargin="296.1163" Scale9Width="144" Scale9Height="38" ctype="ImageViewObjectData">
                <Size X="144.0000" Y="38.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="195.9550" Y="315.1163" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2041" Y="0.4924" />
                <PreSize X="0.1500" Y="0.0594" />
                <FileData Type="Normal" Path="Login/login_server.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgUserNameBack" ActionTag="2115505191" Tag="7" IconVisible="False" LeftMargin="322.7263" RightMargin="309.2737" TopMargin="199.7261" BottomMargin="376.2739" Scale9Width="328" Scale9Height="64" ctype="ImageViewObjectData">
                <Size X="328.0000" Y="64.0000" />
                <Children>
                  <AbstractNodeData Name="txtUserName" ActionTag="1086987833" Tag="10" IconVisible="False" LeftMargin="109.2656" RightMargin="118.7344" TopMargin="17.6809" BottomMargin="19.3191" TouchEnable="True" FontSize="18" IsCustomSize="True" LabelText="" PlaceHolderText="用户名" MaxLengthText="10" ctype="TextFieldObjectData">
                    <Size X="100.0000" Y="27.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="159.2656" Y="32.8191" />
                    <Scale ScaleX="2.8632" ScaleY="1.5228" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4856" Y="0.5128" />
                    <PreSize />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="486.7263" Y="408.2739" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5070" Y="0.6379" />
                <PreSize X="0.3417" Y="0.1000" />
                <FileData Type="Normal" Path="Public/public_input.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgServerBack" ActionTag="-770244142" Tag="9" IconVisible="False" LeftMargin="322.9081" RightMargin="309.0919" TopMargin="279.3011" BottomMargin="296.6989" Scale9Width="328" Scale9Height="64" ctype="ImageViewObjectData">
                <Size X="328.0000" Y="64.0000" />
                <Children>
                  <AbstractNodeData Name="txtServerName" ActionTag="1876027700" Tag="11" IconVisible="False" LeftMargin="79.6343" RightMargin="188.3657" TopMargin="21.5959" BottomMargin="22.4041" FontSize="20" LabelText="服务器" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="TextObjectData">
                    <Size X="60.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="109.6343" Y="32.4041" />
                    <Scale ScaleX="2.9196" ScaleY="1.5646" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.3343" Y="0.5063" />
                    <PreSize />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgState" ActionTag="90495309" Tag="12" IconVisible="False" LeftMargin="271.6164" RightMargin="21.3836" TopMargin="13.6846" BottomMargin="15.3154" Scale9Width="35" Scale9Height="35" ctype="ImageViewObjectData">
                    <Size X="35.0000" Y="35.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="289.1164" Y="32.8154" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.8815" Y="0.5127" />
                    <PreSize X="0.0365" Y="0.0547" />
                    <FileData Type="Normal" Path="Login/selectServer_state1.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="486.9081" Y="328.6989" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5072" Y="0.5136" />
                <PreSize X="0.3417" Y="0.1000" />
                <FileData Type="Normal" Path="Public/public_input.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnStart" ActionTag="1940972044" Tag="26" IconVisible="False" LeftMargin="270.8535" RightMargin="301.1465" TopMargin="401.9748" BottomMargin="124.0252" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="358" Scale9Height="92" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
                <Size X="388.0000" Y="114.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="464.8535" Y="181.0252" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4842" Y="0.2829" />
                <PreSize X="0.4042" Y="0.1781" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Login/login_start.png" Plist="" />
                <PressedFileData Type="Normal" Path="Login/login_start.png" Plist="" />
                <NormalFileData Type="Normal" Path="Login/login_start.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="Login/login_background.jpg" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>